//
// Created by alexander on 25.02.18.
//

#pragma once

#include <boost/asio.hpp>

#include "CApp.hpp"
#include "CMultithreadSupport.hpp"
#include "CClientSocket.h"
#include "CClientSocketHandler.h"

using namespace generated;

namespace client {

    class CAppImpl
            : public CApp {

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::io_service::work> _worker;

        std::shared_ptr<CClientSocket> _client;
        std::shared_ptr<CClientSocketHandler> _handler;

        std::shared_ptr<CMultithreadSupport> _multithread;

    public:

        static std::shared_ptr<CAppImpl> instance();

        void set_multithread_support(const std::shared_ptr<CMultithreadSupport> &multithread_support) override;

        void connect(const std::string &host, int32_t port) override;

        void auth(const std::string &email, const std::string &password) override;

    };

}