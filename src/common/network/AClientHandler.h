#pragma once

#include <memory>
#include <google/protobuf/message.h>

#include "COpCode.h"
#include "CMessage.h"

namespace common {

    class CClient;

    class AClientHandler {

        std::weak_ptr<CClient> _socket;

    public:

        std::shared_ptr<CClient> get_socket() const;

        virtual void on_connected(std::shared_ptr<CClient> socket);

        virtual void on_disconnected(std::shared_ptr<CClient> socket);

        virtual void on_message(std::shared_ptr<CMessage> message) = 0;

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