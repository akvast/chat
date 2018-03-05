#pragma once

#include <vector>

#include "AClientHandler.h"
#include "IClientHandlerListener.h"

using namespace common;

namespace client {

    class CClientHandler
            : public AClientHandler {

        std::weak_ptr<IClientHandlerListener> _listener;

    public:

        void set_listener(std::shared_ptr<IClientHandlerListener> listener);

        void on_connected(std::shared_ptr<CClient> socket) override;

        void on_disconnected(std::shared_ptr<CClient> socket) override;

        void on_message(std::shared_ptr<CMessage> message) override;

        void send_authorize(std::string email, std::string password);

        void send_register(std::string email, std::string password);

        void send_contacts_search(int32_t requestId, std::string query);

    private:

        void send_decrypt_key(std::vector<uint8_t> ecdhPublicKey);

        void handle_server_key(std::vector<uint8_t> data);

        void handle_auth_succeed(std::shared_ptr<CMessage> message);

        void handle_auth_error(std::shared_ptr<CMessage> message);

        void handle_registration_error(std::shared_ptr<CMessage> message);

        void handle_contacts_search_result(std::shared_ptr<CMessage> message);

    };

}