//
// Created by alexander on 24.02.18.
//

#pragma once

#include <boost/asio.hpp>
#include <mysql_driver.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>

namespace server {

    class CDatabase {

        static std::shared_ptr<boost::asio::io_service> s_ioService;

        static sql::Connection *s_connection;

    public:

        static void init(std::shared_ptr<boost::asio::io_service> ioService);

        static void connect(std::string host, std::string user, std::string password, std::string database);

        static void execute(std::function<void(sql::Connection *connection)> func);

    };

}