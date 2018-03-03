#pragma once

#include <boost/asio.hpp>
#include <string>

namespace common {

    class CClient;

}

using namespace common;

namespace server {

    class CServerHandler;

    class CServer {

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;

    public:

        explicit CServer(std::shared_ptr<boost::asio::io_service> ioService, int16_t port);

    private:

        void start_accept();

        void handle_accept(std::shared_ptr<CClient> client,
                           std::shared_ptr<CServerHandler> handler,
                           const boost::system::error_code &error);

    };

}