//
// Created by alexander on 25.02.18.
//

#pragma once

#include <memory>
#include <mutex>

#include "CConnectionState.h"
#include "CClient.h"
#include "CClientHandler.h"
#include "IClientHandlerListener.h"
#include "IConnectionListener.h"

namespace client {

    class CConnection
            : public IClientHandlerListener,
              public std::enable_shared_from_this<CConnection> {

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::io_service::work> _worker;

        std::shared_ptr<CClient> _client;
        std::shared_ptr<CClientHandler> _handler;

        std::mutex _lock;

        CConnectionState _state;

        std::string _host;
        int16_t _port;

        std::vector<std::weak_ptr<IConnectionListener>> _listeners;

    public:

        static std::shared_ptr<CConnection> instance();

        explicit CConnection();

        std::shared_ptr<CClientHandler> get_handler() const;

        void add_listener(std::shared_ptr<IConnectionListener> listener);

        CConnectionState get_state() const;

        void set_host(std::string host);

        void set_port(int16_t port);

        void connect();

        // IClientHandlerListener:

        void on_connected() override;

        void on_handshake_complete() override;

        void on_authorized() override;

        void on_auth_failed() override;

        void on_disconnected() override;

    private:

        void init();

        void notify_state_changed();

    };

}