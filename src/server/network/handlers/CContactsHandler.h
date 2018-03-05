//
// Created by alexander on 05.03.18.
//

#pragma once

#include "AMessageHandler.h"

using namespace common;

namespace server {

    class CContactsHandler
            : public AMessageHandler,
              public std::enable_shared_from_this<CContactsHandler> {

    public:

        CClientState get_required_state() override;

        std::vector<COpCode> get_observable_op_codes() override;

        void handle(COpCode opCode, std::shared_ptr<CMessage> message) override;

    private:

        void handle_contacts_search(std::shared_ptr<CMessage> message);

    };

}