#pragma once

#include <vector>

#include "AClientHandler.h"
#include "ecies.h"

using namespace common;
using namespace ecdh;

namespace server {

    class CClientHandler
            : public AClientHandler {

        EC_KEY *_ecKey;
        std::pair<uint8_t *, size_t> _publicEcKey;
        std::pair<uint8_t *, size_t> _privateEcKey;

    public:

        explicit CClientHandler();

        ~CClientHandler();

        void on_message(std::shared_ptr<CMessage> message) override;

    private:

        // Handshake:

        void send_public_key() const;

        void handle_encrypt_key(std::vector<uint8_t> data);

        void send_decrypt_key();

    };

}