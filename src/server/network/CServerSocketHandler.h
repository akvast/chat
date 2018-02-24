#pragma once

#include <vector>

#include "CSocketHandler.h"
#include "ecies.h"

using namespace common;
using namespace ecdh;

namespace server {

    class CServerSocketHandler
            : public CSocketHandler {

        EC_KEY *_ecKey;
        std::pair<uint8_t *, size_t> _publicEcKey;
        std::pair<uint8_t *, size_t> _privateEcKey;

    public:

        explicit CServerSocketHandler();

        ~CServerSocketHandler();

        void on_connected(std::shared_ptr<CClientSocket> socket) override;

        void on_message(std::shared_ptr<CClientSocket> socket, std::shared_ptr<CMessage> message) override;

        void send_hello(std::shared_ptr<CClientSocket> socket, std::string name);

    private:

        void send_hello(std::shared_ptr<CClientSocket> socket) const;

        void handle_encrypt_key(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data);

        void send_decrypt_key(std::shared_ptr<CClientSocket> socket);

        void handle_auth(std::shared_ptr<CClientSocket> socket, std::vector<uint8_t> data);

    };

}