//
// Created by alexander on 25.02.18.
//

#include <cinttypes>
#include "CAppImpl.h"
#include "CClosureCallback.h"
#include "CLog.h"

namespace generated {

    std::shared_ptr<CApp> CApp::instance() {
        return client::CAppImpl::instance();
    }

}

namespace client {

    std::shared_ptr<CAppImpl> CAppImpl::instance() {
        static auto s_instance = std::make_shared<CAppImpl>();
        return s_instance;
    }

    void CAppImpl::set_multithread_support(const std::shared_ptr<CMultithreadSupport> &multithread_support) {
        _multithread = multithread_support;
    }

    void CAppImpl::connect(const std::string &host, int32_t port) {
        CLog::d("Connect to %s : %" PRId32, host.c_str(), port);

        _ioService = std::make_shared<boost::asio::io_service>();
        _worker = std::make_shared<boost::asio::io_service::work>(*_ioService);

        _handler = std::make_shared<CClientSocketHandler>();
        _client = std::make_shared<CClientSocket>(_ioService, _handler);

        _multithread->start_thread("Client", std::make_shared<CClosureCallback>([=]() {
            CLog::d("Client thread started!");
            _ioService->run();
        }));

        _client->connect(host, static_cast<int16_t>(port));
    }

    void CAppImpl::auth(const std::string &email, const std::string &password) {
        _handler->send_authorize(email, password);
    }

}