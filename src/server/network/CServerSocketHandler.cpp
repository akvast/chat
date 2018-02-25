//
// Created by alexander on 24.02.18.
//

#include <openssl/rand.h>

#include "CServerSocketHandler.h"
#include "CClientSocket.h"
#include "CMessage.h"
#include "CLog.h"
#include "network.pb.h"
#include "CUsersManager.h"
#include "CEmailTools.h"

namespace server {

    CServerSocketHandler::CServerSocketHandler() {

        _ecKey = ecies_key_create();
        _publicEcKey = ecies_key_public_get_binary(_ecKey);
        _privateEcKey = ecies_key_private_get_binary(_ecKey);
    }

    CServerSocketHandler::~CServerSocketHandler() {
        ecies_key_free(_ecKey);
    }

    void CServerSocketHandler::on_message(std::shared_ptr<CMessage> message) {
        switch (message->get_op_code()) {

            // Handshake:

            case COpCode::HandshakeInit:
                send_public_key();
                break;
            case COpCode::HandshakeClientKey:
                handle_encrypt_key(message->get_data());
                send_decrypt_key();
                break;

                // Packets:

            case COpCode::Authorize:
                handle_auth(message);
                break;
            case COpCode::Register:
                handle_register(message);
                break;

            default:
                CLog::d("Unknown packet: %" PRId16, static_cast<uint16_t>(message->get_op_code()));
                break;
        }
    }

    void CServerSocketHandler::send_auth_secceed(std::string name) {
        auto socket = get_socket();
        if (!socket)
            return;

        auto message = std::make_shared<PAuthSucceedMessage>();
        message->set_name(name);

        socket->send(std::make_shared<CMessage>(COpCode::AuthSucceed, message));
    }

    // Private:

    void CServerSocketHandler::send_public_key() const {
        auto socket = get_socket();
        if (!socket)
            return;

        auto data = std::vector<uint8_t>(_publicEcKey.first, _publicEcKey.first + _publicEcKey.second);
        socket->send(std::make_shared<CMessage>(COpCode::HandshakePublicKey, data));
    }

    void CServerSocketHandler::handle_encrypt_key(std::vector<uint8_t> data) {
        auto socket = get_socket();
        if (!socket)
            return;

        // Generate private HEX ECDH key from binary
        auto ecKey = (char *) malloc(_privateEcKey.second * 2 + 1);
        for (int i = 0; i < _privateEcKey.second; ++i)
            sprintf(ecKey + (i * 2), "%02X", _privateEcKey.first[i]);
        ecKey[_privateEcKey.second * 2] = 0;

        // Decrypt message with ECDH private key
        size_t decryptedSize;
        auto decrypted = ecies_decrypt(ecKey, reinterpret_cast<secure_t *>(data.data()), &decryptedSize);

        socket->set_encrypt_key(std::vector<uint8_t>(decrypted, decrypted + decryptedSize));

        free(ecKey);
    }

    void CServerSocketHandler::send_decrypt_key() {
        auto socket = get_socket();
        if (!socket)
            return;

        // Generate AES decrypt key:
        auto decryptKey = std::vector<uint8_t>();
        decryptKey.resize(32);
        memset(decryptKey.data(), 0, 32);
        RAND_bytes(decryptKey.data(), 32);

        socket->set_decrypt_key(decryptKey);

        socket->send(std::make_shared<CMessage>(COpCode::HandshakeServerKey, decryptKey));
    }

    void CServerSocketHandler::handle_auth(std::shared_ptr<CMessage> message) {
        auto authMessage = parse<PAuthMessage>(message);

        if (!authMessage) {
            CLog::d("Invalid AuthMessage packet received.");
            return;
        }

        CLog::d("Received AuthMessage: %s / %s",
                authMessage->email().c_str(),
                authMessage->password().c_str());

        CUsersManager::with_email(authMessage->email(), [=](std::shared_ptr<CUser> user) {
            if (user && user->password == authMessage->password()) {
                send_auth_secceed(user->name);
            } else {
                auto errorMessage = std::make_shared<PErrorMessage>();
                errorMessage->set_code(1); // TODO: Code
                errorMessage->set_message("Invalid email or password");
                send(COpCode::AuthError, errorMessage);
            }
        });
    }

    void CServerSocketHandler::handle_register(std::shared_ptr<CMessage> message) {
        auto registerMessage = parse<PRegisterMessage>(message);

        if (!registerMessage) {
            CLog::d("Invalid RegisterMessage packet received.");
            return;
        }

        CLog::d("Received RegisterMessage: %s / %s",
                registerMessage->email().c_str(),
                registerMessage->password().c_str());

        // TODO: Implement registration

        auto error = std::make_shared<PErrorMessage>();
        error->set_code(1);
        error->set_message("Not yet implemented.");

        send(COpCode::RegisterError, error);
    }

}