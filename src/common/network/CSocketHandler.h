#pragma once

#include <memory>
#include <google/protobuf/message.h>

#include "COpCode.h"
#include "CMessage.h"

namespace common {

    class CClientSocket;

    class CSocketHandler {

        std::weak_ptr<CClientSocket> _socket;

    public:

        virtual void on_connected(std::shared_ptr<CClientSocket> socket);

        std::shared_ptr<CClientSocket> get_socket() const;

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