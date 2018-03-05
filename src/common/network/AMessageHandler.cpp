//
// Created by alexander on 05.03.18.
//

#include "AMessageHandler.h"
#include "AClientHandler.h"
#include "CClient.h"

namespace common {

    void AMessageHandler::set_client_handler(std::shared_ptr<AClientHandler> handler) {
        _clientHandler = handler;
    }

    void AMessageHandler::send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message) {
        if (auto clientHandler = _clientHandler.lock()) {
            clientHandler->send(opCode, message);
        }
    }

    void AMessageHandler::set_state(CClientState state) {
        if (auto clientHandler = _clientHandler.lock()) {
            if (auto socket = clientHandler->get_socket()) {
                socket->set_state(state);
            }
        }
    }

}