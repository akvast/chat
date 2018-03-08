//
// Created by alexander on 24.02.18.
//

#include <openssl/rand.h>

#include <utility>

#include "CClientHandler.h"
#include "CMessage.h"
#include "CClient.h"
#include "CLog.h"
#include "ecies.h"
#include "network.pb.h"
#include "CSearchAdapterImpl.h"
#include "CAppImpl.h"

using namespace ecdh;
using namespace common;

namespace client {

    void CClientHandler::set_listener(std::shared_ptr<IClientHandlerListener> listener) {
        _listener = listener;
    }

    void CClientHandler::on_connected(std::shared_ptr<CClient> socket) {
        AClientHandler::on_connected(socket);
        if (auto listener = _listener.lock())
            listener->on_connected();

        socket->set_encrypt_key({});
        socket->set_decrypt_key({});

        auto message = std::make_shared<CMessage>(COpCode::HandshakeInit, nullptr);
        socket->send(message);
    }

    void CClientHandler::on_disconnected(std::shared_ptr<CClient> socket) {
        AClientHandler::on_disconnected(socket);
        if (auto listener = _listener.lock())
            listener->on_disconnected();
    }

    void CClientHandler::on_message(std::shared_ptr<CMessage> message) {

        switch (COpCode(message->get_op_code())) {

            case COpCode::HandshakePublicKey:
                send_decrypt_key(message->get_data());
                break;
            case COpCode::HandshakeServerKey:
                handle_server_key(message->get_data());
                break;

            case COpCode::AuthSucceed:
                handle_auth_succeed(message);
                break;
            case COpCode::AuthError:
                handle_auth_error(message);
                break;

            case COpCode::ContactsSearchResult:
                handle_contacts_search_result(message);
                break;

            default:
                CLog::d("Received unknown message: %" PRId16, static_cast<uint16_t>(message->get_op_code()));
                break;
        }
    }

    void CClientHandler::send_authorize() {
        const auto &app = CAppImpl::instance();

        auto message = std::make_shared<PAuthMessage>();
        message->set_token(app->get_token());
        message->set_name(app->get_name());
        message->set_email(app->get_email());
        message->set_avatar_url(app->get_avatar_url());

        send(COpCode::Authorize, message);
    }

    void CClientHandler::send_contacts_search(int32_t requestId, std::string query) {
        auto message = std::make_shared<PContactsSearchRequest>();
        message->set_request_id(requestId);
        message->set_query(query);
        send(COpCode::ContactsSearch, message);
    }

    // Private:

    void CClientHandler::send_decrypt_key(std::vector<uint8_t> ecdhPublicKey) {
        CLog::d("CClientHandler::send_decrypt_key");

        auto socket = get_socket();
        if (!socket)
            return;

        // Generate AES decrypt key:
        auto decryptKey = std::vector<uint8_t>();
        decryptKey.resize(32);
        memset(decryptKey.data(), 0, 32);
        RAND_bytes(decryptKey.data(), 32);

        socket->set_decrypt_key(decryptKey);

        // Create hex ECDH key from binary
        auto ecKey = (char *) malloc(ecdhPublicKey.size() * 2 + 1);
        for (int i = 0; i < ecdhPublicKey.size(); ++i)
            sprintf(ecKey + (i * 2), "%02X", ecdhPublicKey[i]);
        ecKey[ecdhPublicKey.size() * 2] = 0;

        CLog::d("ECDH public key received: %s", ecKey);

        // Encrypt AES key with private ECDH
        auto key = ecies_key_create_public_octets(ecdhPublicKey.data(), ecdhPublicKey.size());
        auto secure = ecies_encrypt(ecKey, decryptKey.data(), decryptKey.size());
        ecies_key_free(key);
        free(ecKey);

        // Send encrypted AES key
        auto message = std::make_shared<CMessage>(COpCode::HandshakeClientKey,
                                                  std::vector<uint8_t>(secure, secure + secure_total_length(secure)));

        socket->send(message);
    }

    void CClientHandler::handle_server_key(std::vector<uint8_t> data) {
        auto socket = get_socket();
        if (!socket)
            return;

        // Save AES encrypt key
        socket->set_encrypt_key(std::move(data));

        if (auto listener = _listener.lock())
            listener->on_handshake_complete();
    }

    void CClientHandler::handle_auth_succeed(std::shared_ptr<CMessage> message) {
        auto authSucceedMessage = parse<PAuthSucceedMessage>(message);

        if (!authSucceedMessage) {
            CLog::d("Invalid AuthSucceedMessage packet received.");
            return;
        }

        CLog::d("AuthSucceedMessage received: %" PRId64 " userId" + authSucceedMessage->id());

        if (auto listener = _listener.lock())
            listener->on_authorized();
    }

    void CClientHandler::handle_auth_error(std::shared_ptr<CMessage> message) {
        auto errorMessage = parse<PErrorMessage>(message);

        if (!errorMessage) {
            if (auto listener = _listener.lock())
                listener->on_auth_failed();

            CLog::d("Invalid ErrorMessage packet received.");
            return;
        }

        CLog::d("ErrorMessage received: %" PRId32 " : %s", errorMessage->code(), errorMessage->message().c_str());

        if (auto listener = _listener.lock())
            listener->on_auth_failed();
    }

    void CClientHandler::handle_contacts_search_result(std::shared_ptr<CMessage> message) {
        auto response = parse<PContactsSearchResponse>(message);

        CLog::d("Search response: %d users", response->users_size());
        for (int i = 0; i < response->users_size(); ++i) {
            const PUser &user = response->users(i);
            CLog::d("\t %s [%" PRId64 "]", user.name().c_str(), user.id());
        }

        CSearchAdapterImpl::instance()->on_search_response(response);
    }

}