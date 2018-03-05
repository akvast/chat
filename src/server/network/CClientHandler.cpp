//
// Created by alexander on 24.02.18.
//

#include <openssl/rand.h>

#include "CClientHandler.h"
#include "CClient.h"
#include "CLog.h"
#include "CUsersManager.h"

namespace server {

    CClientHandler::CClientHandler() {

        _ecKey = ecies_key_create();
        _publicEcKey = ecies_key_public_get_binary(_ecKey);
        _privateEcKey = ecies_key_private_get_binary(_ecKey);
    }

    CClientHandler::~CClientHandler() {
        ecies_key_free(_ecKey);
    }

    void CClientHandler::on_message(std::shared_ptr<CMessage> message) {
        switch (message->get_op_code()) {

            // Handshake:

            case COpCode::HandshakeInit:
                send_public_key();
                break;
            case COpCode::HandshakeClientKey:
                handle_encrypt_key(message->get_data());
                send_decrypt_key();
                break;

            default:
                AClientHandler::on_message(message);
                break;
        }
    }

    // Private:

    void CClientHandler::send_public_key() const {
        auto socket = get_socket();
        if (!socket)
            return;

        auto data = std::vector<uint8_t>(_publicEcKey.first, _publicEcKey.first + _publicEcKey.second);
        socket->send(std::make_shared<CMessage>(COpCode::HandshakePublicKey, data));
    }

    void CClientHandler::handle_encrypt_key(std::vector<uint8_t> data) {
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
        free(ecKey);

        if (decrypted == nullptr) {
            socket->get_socket()->close();
            return;
        }

        socket->set_encrypt_key(std::vector<uint8_t>(decrypted, decrypted + decryptedSize));
    }

    void CClientHandler::send_decrypt_key() {
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
        socket->set_state(CClientState::Unauthorized);
    }

}