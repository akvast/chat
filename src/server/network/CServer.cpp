//
// Created by alexander on 23.02.18.
//

#include "CServer.h"

#include <boost/bind.hpp>
#include <iostream>

#include "CClient.h"
#include "CClientHandler.h"
#include "CLog.h"

#include "CAuthHandler.h"
#include "CContactsHandler.h"

namespace server {

    CServer::CServer(std::shared_ptr<boost::asio::io_service> ioService, int16_t port)
            : _ioService(std::move(ioService)) {

        auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), static_cast<unsigned short>(port));
        _acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(*_ioService, endpoint);
    }

    void CServer::start() {
        start_accept();
    }

    // Private:

    void CServer::start_accept() {
        auto handler = std::make_shared<CClientHandler>();

        handler->add_message_handler(std::make_shared<CAuthHandler>());
        handler->add_message_handler(std::make_shared<CContactsHandler>());

        auto client = std::make_shared<CClient>(_ioService, handler);
        auto socket = client->get_socket();

        _acceptor->async_accept(*socket, boost::bind(&CServer::handle_accept,
                                                     shared_from_this(),
                                                     client,
                                                     boost::asio::placeholders::error));
    }

    void CServer::handle_accept(std::shared_ptr<CServer> server,
                                std::shared_ptr<CClient> client,
                                const boost::system::error_code &error) {

        CLog::d("Socket accepted.");

        client->on_connected();
        client->start_read();

        server->start_accept();
    }

}