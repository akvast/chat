#include "CSocketHandler.h"
#include "CClientSocket.h"

namespace common {

    void CSocketHandler::on_connected(std::shared_ptr<CClientSocket> socket) {
        _socket = socket;
    }

    std::shared_ptr<CClientSocket> CSocketHandler::get_socket() const {
        return _socket.lock();
    }

    void CSocketHandler::send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message) {
        auto socket = get_socket();
        if (!socket)
            return;

        socket->send(std::make_shared<CMessage>(opCode, message));
    }

}