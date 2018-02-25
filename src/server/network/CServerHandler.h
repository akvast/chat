#pragma once

#include <vector>

#include "AClientHandler.h"
#include "ecies.h"

using namespace common;
using namespace ecdh;

namespace server {

    class CServerHandler
            : public AClientHandler {

        EC_KEY *_ecKey;
        std::pair<uint8_t *, size_t> _publicEcKey;
        std::pair<uint8_t *, size_t> _privateEcKey;

    public:

        explicit CServerHandler();

        ~CServerHandler();

        void on_message(std::shared_ptr<CMessage> message) override;

        void send_auth_secceed(std::string name);

    private:

        // Handshake:

        void send_public_key() const;

        void handle_encrypt_key(std::vector<uint8_t> data);

        void send_decrypt_key();

        // Packets:

        void handle_auth(std::shared_ptr<CMessage> message);

        void handle_register(std::shared_ptr<CMessage> message);

    };

}