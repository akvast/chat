#include "AClientHandler.h"
#include "CClient.h"

namespace common {

    std::shared_ptr<CClient> AClientHandler::get_socket() const {
        return _socket.lock();
    }

    void AClientHandler::on_connected(std::shared_ptr<CClient> socket) {
        _socket = socket;
    }

    void AClientHandler::on_disconnected(std::shared_ptr<CClient> socket) {

    }

    void AClientHandler::send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message) {
        auto socket = get_socket();
        if (!socket)
            return;

        socket->send(std::make_shared<CMessage>(opCode, message));
    }

}