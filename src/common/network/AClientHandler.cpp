#include "AClientHandler.h"

#include <cinttypes>

#include "CClient.h"
#include "CLog.h"
#include "AMessageHandler.h"

namespace common {

    std::shared_ptr<CClient> AClientHandler::get_socket() const {
        return _socket.lock();
    }

    void AClientHandler::add_message_handler(std::shared_ptr<AMessageHandler> messageHandler) {
        auto self = shared_from_this();
        messageHandler->set_client_handler(self);
        for (auto opCode : messageHandler->get_observable_op_codes()) {
            _messageHandlers.emplace(static_cast<uint16_t>(opCode), messageHandler);
        }
    }

    void AClientHandler::on_connected(std::shared_ptr<CClient> socket) {
        _socket = socket;
    }

    void AClientHandler::on_disconnected(std::shared_ptr<CClient> socket) {

    }

    void AClientHandler::on_message(std::shared_ptr<CMessage> message) {
        auto socket = _socket.lock();
        if (!socket)
            return;

        auto res = _messageHandlers.find(static_cast<uint16_t>(message->get_op_code()));
        if (res == _messageHandlers.end()) {
            CLog::d("Unknown packet: %" PRId16, static_cast<uint16_t>(message->get_op_code()));
            return;
        }

        auto handler = res->second;
        auto state = res->second->get_required_state();

        if (socket->get_state() != state) {
            CLog::d("Invalid state for handler packet: %" PRId16, static_cast<uint16_t>(message->get_op_code()));
            // TODO: Disconnect?
            return;
        }

        handler->handle(message->get_op_code(), message);
    }

    void AClientHandler::send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message) {
        auto socket = get_socket();
        if (!socket)
            return;

        socket->send(std::make_shared<CMessage>(opCode, message));
    }

}