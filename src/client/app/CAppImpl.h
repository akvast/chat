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

        std::string _token;
        std::string _name;
        std::string _email;
        std::string _avatarUrl;

    public:

        static std::shared_ptr<CAppImpl> instance();

        void set_concurrency(const std::shared_ptr<CConcurrency> &concurrency) override;

        void set_host(const std::string &host) override;

        void set_port(int32_t port) override;

        void set_token(const std::string &token) override;

        std::string get_token() const;

        void set_name(const std::string &name) override;

        std::string get_name() const;

        void set_email(const std::string &email) override;

        std::string get_email() const;

        void set_avatar_url(const std::string &avatarUrl) override;

        std::string get_avatar_url() const;

        void open_database(const std::string &path) override;

        void connect() override;

        void start_thread(const std::string &name, std::function<void()> runnable);

        void execute_in_ui(std::function<void()> runnable);

    };

}