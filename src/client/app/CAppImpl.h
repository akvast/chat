//
// Created by alexander on 25.02.18.
//

#pragma once

#include <boost/asio.hpp>

#include "CApp.hpp"
#include "CConnection.h"
#include "CConcurrency.hpp"

using namespace generated;

namespace client {

    class CAppImpl
            : public CApp {

        std::shared_ptr<CConcurrency> _concurrency;

        std::shared_ptr<CConnection> _connection;

        std::string _email;
        std::string _password;

    public:

        static std::shared_ptr<CAppImpl> instance();

        void set_concurrency(const std::shared_ptr<CConcurrency> &concurrency) override;

        void set_host(const std::string &host) override;

        void set_port(int32_t port) override;

        void set_email(const std::string &email) override;

        std::string get_email() const;

        void set_password(const std::string &password) override;

        std::string get_password() const;

        void connect() override;

        void start_thread(const std::string &name, std::function<void()> runnable);

    };

}