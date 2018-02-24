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

namespace server {

    CServerSocketHandler::CServerSocketHandler() {

        _ecKey = ecies_key_create();
        _publicEcKey = ecies_key_public_get_binary(_ecKey);
        _privateEcKey = ecies_key_private_get_binary(_ecKey);
    }

    CServerSocketHandler::~CServerSocketHandler() {
        ecies_key_free(_ecKey);
    }

    void CServerSocketHandler::on_connected(std::shared_ptr<CClientSocket> socket) {

    }

    void CServerSocketHandler::on_message(std::shared_ptr<CClientSocket> socket, std::shared_ptr<CMessage> message) {
        switch (message->get_op_code()) {
            case 1:
                send_hello(socket);
                break;
            case 2:
                handle_encrypt_key(socket, message->get_data());
                send_decrypt_key(socket);
                break;
            case 3:
                handle_auth(socket, message->get_data());
                break;
            default:
                CLog::d("Unknown packet: " + std::to_string(message->get_op_code()));
                break;
        }
    }

    void CServerSocketHandler::send_hello(std::shared_ptr<CClientSocket> socket, std::string name) {
        auto message = std::make_shared<PHelloMessage>();
        message->set_name(name);

        socket->send(std::make_shared<CMessage>(3, message));
    }

    // Private:

    void CServerSocketHandler::send_hello(std::shared_ptr<CClientSocket> socket) const {
        auto data = std::vector<uint8_t>(_publicEcKey.first, _publicEcKey.first + _publicEcKey.second);
        socket->send(std::make_shared<CMessage>(1, data));
    }

    void CServerSocketHandler::handle_encrypt_key(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data) {

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

    void CServerSocketHandler::send_decrypt_key(std::shared_ptr<CClientSocket> socket) {
        // Generate AES decrypt key:
        auto decryptKey = std::vector<uint8_t>();
        decryptKey.resize(32);
        memset(decryptKey.data(), 0, 32);
        RAND_bytes(decryptKey.data(), 32);

        socket->set_decrypt_key(decryptKey);

        socket->send(std::make_shared<CMessage>(2, decryptKey));
    }

    void CServerSocketHandler::handle_auth(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data) {

        auto authMessage = std::make_shared<PAuthMessage>();
        bool isParsed = authMessage->ParseFromArray(data.data(), data.size());

        if (!isParsed) {
            CLog::d("Invalid packet received.");
            socket->get_socket()->close();
            return;
        }

        CLog::d("Received AuthMessage: " + authMessage->login() + " / " + authMessage->password());
        CUsersManager::with_login(authMessage->login(), [=](std::shared_ptr<CUser> user) {
            if (user && user->get_password() == authMessage->password()) {
                send_hello(socket, user->get_name());
            } else {
                socket->send(std::make_shared<CMessage>(4, std::vector<uint8_t>{}));
            }
        });
    }

}