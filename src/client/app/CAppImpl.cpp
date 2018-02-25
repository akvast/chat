//
// Created by alexander on 25.02.18.
//

#include <cinttypes>
#include "CAppImpl.h"
#include "CClosureRunnable.h"

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

    void CAppImpl::set_concurrency(const std::shared_ptr<CConcurrency> &concurrency) {
        _concurrency = concurrency;
        _connection = CConnection::instance();
    }

    void CAppImpl::set_host(const std::string &host) {
        _connection->set_host(host);
    }

    void CAppImpl::set_port(int32_t port) {
        _connection->set_port(static_cast<int16_t>(port));
    }

    void CAppImpl::set_email(const std::string &email) {
        _email = email;
    }

    std::string CAppImpl::get_email() const {
        return _email;
    }

    void CAppImpl::set_password(const std::string &password) {
        _password = password;
    }

    std::string CAppImpl::get_password() const {
        return _password;
    }

    void CAppImpl::connect() {
        _connection->connect();
    }

    void CAppImpl::start_thread(const std::string &name, std::function<void()> runnable) {
        if (_concurrency) {
            _concurrency->start_thread(name, std::make_shared<CClosureRunnable>(runnable));
            return;
        }

        // TODO: Add pending thread
    }

}