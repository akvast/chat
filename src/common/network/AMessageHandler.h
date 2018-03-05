//
// Created by alexander on 05.03.18.
//

#pragma once

#include <vector>
#include <memory>

#include <google/protobuf/message.h>

#include "COpCode.h"
#include "CClientState.h"
#include "AClientHandler.h"

namespace common {

    class CMessage;

    class AMessageHandler {

        std::weak_ptr<AClientHandler> _clientHandler;

    public:

        void set_client_handler(std::shared_ptr<AClientHandler> handler);

        virtual CClientState get_required_state() = 0;

        virtual std::vector<COpCode> get_observable_op_codes() = 0;

        virtual void handle(COpCode opCode, std::shared_ptr<CMessage> message) = 0;

        void send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message);

        template<typename T>
        std::shared_ptr<T> parse(const std::shared_ptr<CMessage> &message) {
            if (auto handler = _clientHandler.lock())
                return handler->parse<T>(message);
        }

        void set_state(CClientState state);

    };

}