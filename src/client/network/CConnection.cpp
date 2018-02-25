//
// Created by alexander on 25.02.18.
//

#include "CConnection.h"
#include "CAppImpl.h"
#include "CLog.h"

using namespace common;

namespace client {

    std::shared_ptr<CConnection> CConnection::instance() {
        static std::shared_ptr<CConnection> s_instance;
        if (!s_instance) {
            s_instance = std::make_shared<CConnection>();
            s_instance->init();
        }
        return s_instance;
    }

    CConnection::CConnection()
            : _state(CConnectionState::Disconnected) {

        _ioService = std::make_shared<boost::asio::io_service>();
        _worker = std::make_shared<boost::asio::io_service::work>(*_ioService);

        _handler = std::make_shared<CClientHandler>();
        _client = std::make_shared<CClient>(_ioService, _handler);

        CAppImpl::instance()->start_thread("Client", [=]() {
            CLog::d("Client thread started!");
            _ioService->run();
        });
    }

    void CConnection::add_listener(std::shared_ptr<IConnectionListener> listener) {
        _lock.lock();
        _listeners.emplace_back(listener);
        _lock.unlock();
    }

    CConnectionState CConnection::get_state() const {
        return _state;
    }

    void CConnection::set_host(std::string host) {
        _host = std::move(host);
    }

    void CConnection::set_port(int16_t port) {
        _port = port;
    }

    void CConnection::connect() {
        _lock.lock();
        _state = CConnectionState::Connecting;
        _client->connect(_host, _port);
        _lock.unlock();

        notify_state_changed();
    }

    // CClientSocketListener:

    void CConnection::on_connected() {

    }

    void CConnection::on_handshake_complete() {
        CLog::d("CConnection::on_handshake_complete");

        auto app = CAppImpl::instance();
        _handler->send_authorize(app->get_email(), app->get_password());
    }

    void CConnection::on_authorized() {
        _lock.lock();
        _state = CConnectionState::Connected;
        _lock.unlock();

        notify_state_changed();
    }

    void CConnection::on_auth_failed() {
        CLog::d("CConnection::on_auth_failed");
        _lock.lock();
        _state = CConnectionState::Unauthorized;
        _client->disconnect();
        _lock.unlock();

        notify_state_changed();
    }

    void CConnection::on_disconnected() {
        CLog::d("CConnection::on_disconnected");
        _lock.lock();
        if (_state != CConnectionState::Unauthorized)
            _client->connect(_host, _port);
        _state = CConnectionState::Disconnected;
        _lock.unlock();

        notify_state_changed();
    }

    // Private:

    void CConnection::init() {
        _handler->set_listener(shared_from_this());
    }

    void CConnection::notify_state_changed() {
        _lock.lock();
        _listeners.erase(
                std::remove_if(
                        _listeners.begin(),
                        _listeners.end(),
                        [](const std::weak_ptr<IConnectionListener> &ptr) {
                            if (auto listener = ptr.lock()) {
                                listener->on_state_changed();
                                return false;
                            }
                            return true;
                        }), _listeners.end());
        _lock.unlock();
    }

}