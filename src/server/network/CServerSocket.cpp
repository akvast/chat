//
// Created by alexander on 23.02.18.
//

#include "CServerSocket.h"

#include <boost/bind.hpp>
#include <iostream>

#include "CClientSocket.h"
#include "CServerSocketHandler.h"
#include "CLog.h"

namespace server {

    CServerSocket::CServerSocket(std::shared_ptr<boost::asio::io_service> ioService, int16_t port)
            : _ioService(std::move(ioService)) {

        auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), static_cast<unsigned short>(port));
        _acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(*_ioService, endpoint);

        start_accept();
    }

    // Private:

    void CServerSocket::start_accept() {
        auto handler = std::make_shared<CServerSocketHandler>();
        auto client = std::make_shared<CClientSocket>(_ioService, handler);
        auto socket = client->get_socket();

        _acceptor->async_accept(*socket, boost::bind(&CServerSocket::handle_accept, this,
                                                     client,
                                                     boost::asio::placeholders::error));
    }

    void CServerSocket::handle_accept(std::shared_ptr<CClientSocket> client, const boost::system::error_code &) {
        CLog::d("Socket accepted.");
        _clients.push_back(client);
        client->start_read();
        start_accept();
    }

}