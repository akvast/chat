#pragma once

#include <vector>

#include "CSocketHandler.h"

using namespace common;

namespace client {

    class CClientSocketHandler
            : public CSocketHandler {

    public:

        void on_connected(std::shared_ptr<CClientSocket> socket) override;

        void on_message(std::shared_ptr<CMessage> message) override;

        void send_authorize(std::string email, std::string password);

        void send_register(std::string email, std::string password);

    private:

        void send_decrypt_key(std::vector<uint8_t> ecdhPublicKey);

        void handle_server_key(std::vector<uint8_t> data);

        void handle_hello(std::shared_ptr<CMessage> message);

        void handle_registration_error(std::shared_ptr<CMessage> message);

    };

}