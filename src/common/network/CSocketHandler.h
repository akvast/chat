#pragma once

#include <memory>

namespace common {

    class CMessage;

    class CClientSocket;

    class CSocketHandler {

    public:

        virtual void on_connected(std::shared_ptr<CClientSocket> socket) = 0;

        virtual void on_message(std::shared_ptr<CClientSocket> socket, std::shared_ptr<CMessage> message) = 0;

    };

}