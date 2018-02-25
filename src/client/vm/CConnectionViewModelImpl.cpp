//
// Created by alexander on 25.02.18.
//

#include "CConnectionViewModelImpl.h"

namespace generated {

    std::shared_ptr<CConnectionViewModel> CConnectionViewModel::instance() {
        return client::CConnectionViewModelImpl::instance();
    }

}

namespace client {

    std::shared_ptr<CConnectionViewModelImpl> CConnectionViewModelImpl::instance() {
        static std::shared_ptr<CConnectionViewModelImpl> s_instance;
        if (!s_instance) {
            s_instance = std::make_shared<CConnectionViewModelImpl>();
            s_instance->init();
        }
        return s_instance;
    }

    CConnectionViewModelImpl::CConnectionViewModelImpl()
            : _connection(CConnection::instance()) {

        _isAuthFailed = false;
    }

    std::shared_ptr<CViewModel> CConnectionViewModelImpl::get_base() {
        return shared_from_this();
    }

    bool CConnectionViewModelImpl::is_connected() {
        return _connection->get_state() == CConnectionState::Connected;
    }

    bool CConnectionViewModelImpl::is_connecting() {
        return _connection->get_state() == CConnectionState::Connecting;
    }

    bool CConnectionViewModelImpl::is_auth_failed() {
        return _isAuthFailed;
    }

    // IConnectionListener:

    void CConnectionViewModelImpl::on_state_changed() {
        if (_connection->get_state() == CConnectionState::Unauthorized)
            _isAuthFailed = true;
        notify();
    }

    // Private:

    void CConnectionViewModelImpl::init() {
        _connection->add_listener(shared_from_this());
    }

}