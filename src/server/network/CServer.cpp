//
// Created by alexander on 23.02.18.
//

#include "CServer.h"

#include <boost/bind.hpp>
#include <iostream>

#include "CClient.h"
#include "CServerHandler.h"
#include "CLog.h"

namespace server {

    CServer::CServer(std::shared_ptr<boost::asio::io_service> ioService, int16_t port)
            : _ioService(std::move(ioService)) {

        auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), static_cast<unsigned short>(port));
        _acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(*_ioService, endpoint);

        start_accept();
    }

    // Private:

    void CServer::start_accept() {
        auto handler = std::make_shared<CServerHandler>();
        auto client = std::make_shared<CClient>(_ioService, handler);
        auto socket = client->get_socket();

        _acceptor->async_accept(*socket, boost::bind(&CServer::handle_accept, this,
                                                     client, handler,
                                                     boost::asio::placeholders::error));
    }

    void CServer::handle_accept(std::shared_ptr<CClient> client,
                                      std::shared_ptr<CServerHandler> handler,
                                      const boost::system::error_code &) {
        CLog::d("Socket accepted.");
        _clients.push_back(client);

        handler->on_connected(client);
        client->start_read();

        start_accept();
    }

}