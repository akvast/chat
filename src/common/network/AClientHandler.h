#pragma once

#include <memory>
#include <unordered_map>
#include <google/protobuf/message.h>

#include "COpCode.h"
#include "CMessage.h"

namespace common {

    class CClient;

    class AMessageHandler;

    class AClientHandler
            : public std::enable_shared_from_this<AClientHandler> {

        std::weak_ptr<CClient> _socket;

        std::unordered_map<uint16_t, std::shared_ptr<AMessageHandler>> _messageHandlers{};

    public:

        std::shared_ptr<CClient> get_socket() const;

        void add_message_handler(std::shared_ptr<AMessageHandler> messageHandler);

        virtual void on_connected(std::shared_ptr<CClient> socket);

        virtual void on_disconnected(std::shared_ptr<CClient> socket);

        virtual void on_message(std::shared_ptr<CMessage> message);

        void send(COpCode opCode, const std::shared_ptr<google::protobuf::Message> &message);

        template<typename T>
        std::shared_ptr<T> parse(const std::shared_ptr<CMessage> &message) {
            auto data = message->get_data();
            auto packet = std::make_shared<T>();
            bool isParsed = packet->ParseFromArray(data.data(), data.size());

            if (!isParsed) {
                return nullptr;
            }

            return packet;
        }

    };

}