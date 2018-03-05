#pragma once

#include <boost/asio.hpp>
#include <string>

namespace common {

    class CClient;

}

using namespace common;

namespace server {

    class CClientHandler;

    class CServer
            : public std::enable_shared_from_this<CServer> {

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::ip::tcp::acceptor> _acceptor;

    public:

        explicit CServer(std::shared_ptr<boost::asio::io_service> ioService, int16_t port);

        void start();

    private:

        void start_accept();

        static void handle_accept(std::shared_ptr<CServer> server,
                                  std::shared_ptr<CClient> client,
                                  const boost::system::error_code &error);

    };

}