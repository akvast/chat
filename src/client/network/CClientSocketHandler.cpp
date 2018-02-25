//
// Created by alexander on 24.02.18.
//

#include <openssl/rand.h>

#include <utility>

#include "CClientSocketHandler.h"
#include "CMessage.h"
#include "CClientSocket.h"
#include "CLog.h"
#include "ecies.h"
#include "network.pb.h"

using namespace ecdh;
using namespace common;

namespace client {

    void CClientSocketHandler::on_connected(std::shared_ptr<CClientSocket> socket) {
        CSocketHandler::on_connected(socket);

        auto message = std::make_shared<CMessage>(COpCode::HandshakeInit, nullptr);
        socket->send(message);
    }

    void CClientSocketHandler::on_message(std::shared_ptr<CMessage> message) {

        switch (COpCode(message->get_op_code())) {

            case COpCode::HandshakePublicKey:
                send_decrypt_key(message->get_data());
                break;
            case COpCode::HandshakeServerKey:
                handle_server_key(message->get_data());
                break;

            case COpCode::AuthSucceed:
                handle_hello(message);
                break;
            case COpCode::AuthError:
                // TODO:
                CLog::d("Invalid login / password.");
                break;
            case COpCode::RegisterError:
                handle_registration_error(message);
                break;

            default:
                CLog::d("Received unknown message: " + std::to_string(static_cast<uint16_t>(message->get_op_code())));
                break;
        }
    }

    void CClientSocketHandler::send_authorize(std::string email,
                                              std::string password) {

        auto message = std::make_shared<PAuthMessage>();
        message->set_email(email);
        message->set_password(password);

        send(COpCode::Authorize, message);
    }

    void CClientSocketHandler::send_register(std::string email,
                                             std::string password) {

        auto message = std::make_shared<PRegisterMessage>();
        message->set_email(email);
        message->set_password(password);

        send(COpCode::Register, message);
    }

    // Private:

    void CClientSocketHandler::send_decrypt_key(std::vector<uint8_t> ecdhPublicKey) {
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

    void CClientSocketHandler::handle_server_key(std::vector<uint8_t> data) {
        auto socket = get_socket();
        if (!socket)
            return;

        // Save AES encrypt key
        socket->set_encrypt_key(std::move(data));
    }

    void CClientSocketHandler::handle_hello(std::shared_ptr<CMessage> message) {
        auto authSucceedMessage = parse<PAuthSucceedMessage>(message);

        if (!authSucceedMessage) {
            CLog::d("Invalid AuthSucceedMessage packet received.");
            return;
        }

        CLog::d("HelloMessage received: " + authSucceedMessage->name());
    }

    void CClientSocketHandler::handle_registration_error(std::shared_ptr<CMessage> message) {
        auto errorMessage = parse<PErrorMessage>(message);

        if (!errorMessage) {
            CLog::d("Invalid ErrorMessage packet received.");
            return;
        }

        CLog::d("ErrorMessage received: %" PRId32 " : %s", errorMessage->code(), errorMessage->message().c_str());
    }

}