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
        auto message = std::make_shared<CMessage>(1, std::vector<uint8_t>{0, 1, 2, 3});
        socket->send(message);
    }

    void CClientSocketHandler::on_message(std::shared_ptr<CClientSocket> socket, std::shared_ptr<CMessage> message) {
        switch (message->get_op_code()) {
            case 1:
                send_decrypt_key(socket, message->get_data());
                break;
            case 2:
                handle_encrypt_key(socket, message->get_data());
                break;
            case 3:
                handle_hello(socket, message->get_data());
                break;
            case 4:
                CLog::d("Invalid login / password.");
                break;
            default:
                CLog::d("Received unknown message: " + std::to_string(message->get_op_code()));
                break;
        }
    }

    void CClientSocketHandler::send_auth(std::shared_ptr<CClientSocket> socket,
                                         std::string login,
                                         std::string password) {

        auto message = std::make_shared<PAuthMessage>();
        message->set_login(login);
        message->set_password(password);

        socket->send(std::make_shared<CMessage>(3, message));
    }

    // Private:

    void CClientSocketHandler::send_decrypt_key(std::shared_ptr<CClientSocket> socket,
                                                std::vector<uint8_t> ecdhPublicKey) {

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
        auto message = std::make_shared<CMessage>(2,
                                                  std::vector<uint8_t>(secure, secure + secure_total_length(secure)));
        socket->send(message);
    }

    void CClientSocketHandler::handle_encrypt_key(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data) {
        // Save AES encrypt key
        socket->set_encrypt_key(std::move(data));
    }

    void CClientSocketHandler::handle_hello(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data) {

        auto helloMessage = std::make_shared<PHelloMessage>();
        bool isParsed = helloMessage->ParseFromArray(data.data(), data.size());

        if (!isParsed) {
            CLog::d("Invalid packet received.");
            socket->get_socket()->close();
            return;
        }

        CLog::d("PHelloMessage received: " + helloMessage->name());
    }

}