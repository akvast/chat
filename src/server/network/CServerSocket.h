#pragma once

#include <boost/asio.hpp>
#include <string>

namespace common {

    class CClientSocket;

}

using namespace common;

namespace server {

    class CServerSocketHandler;

    class CServerSocket {

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;

        std::vector<std::shared_ptr<CClientSocket>> _clients;

    public:

        explicit CServerSocket(std::shared_ptr<boost::asio::io_service> ioService, int16_t port);

    private:

        void start_accept();

        void handle_accept(std::shared_ptr<CClientSocket> client,
                           std::shared_ptr<CServerSocketHandler> handler,
                           const boost::system::error_code &error);

    };

}