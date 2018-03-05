//
// Created by alexander on 05.03.18.
//

#pragma once

#include "AMessageHandler.h"

using namespace common;

namespace server {

    class CAuthHandler
            : public AMessageHandler {

    public:

        CClientState get_required_state() override;

        std::vector<COpCode> get_observable_op_codes() override;

        void handle(COpCode opCode, std::shared_ptr<CMessage> message) override;

    private:

        void handle_auth(std::shared_ptr<CMessage> message);

        void send_auth_succeed(std::string name);

        void handle_register(std::shared_ptr<CMessage> message);

    };

}