//
// Created by alexander on 25.02.18.
//

#include <cinttypes>
#include "CAppImpl.h"
#include "CClosureRunnable.h"
#include "CDatabase.h"
#include "CDialog.h"
#include "CDialogsManager.h"

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

    void CAppImpl::set_token(const std::string &token) {
        _token = token;
    }

    std::string CAppImpl::get_token() const {
        return _token;
    }

    void CAppImpl::set_name(const std::string &name) {
        _name = name;
    }

    std::string CAppImpl::get_name() const {
        return _name;
    }

    void CAppImpl::set_email(const std::string &email) {
        _email = email;
    }

    std::string CAppImpl::get_email() const {
        return _email;
    }

    void CAppImpl::set_avatar_url(const std::string &avatarUrl) {
        _avatarUrl = avatarUrl;
    }

    std::string CAppImpl::get_avatar_url() const {
        return _avatarUrl;
    }

    void CAppImpl::open_database(const std::string &path) {
        // TODO:

        CDatabase::init();
        CDatabase::open(path, "ASAUNRLSAFAFSRC", [](bool isOpened) {
            // TODO:
        });
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

    void CAppImpl::execute_in_ui(std::function<void()> runnable) {
        if (_concurrency) {
            _concurrency->execute_in_ui(std::make_shared<CClosureRunnable>(runnable));
        }
    }

}