//
// Created by alexander on 03.03.18.
//

#pragma once

#include <boost/asio.hpp>
#include <string>
#include "sqlite3.h"

#include "CSqliteStmt.h"

namespace client {

    class CDatabase {

        static std::shared_ptr<boost::asio::io_service> s_ioService;
        static std::shared_ptr<boost::asio::io_service::work> s_worker;

        static sqlite3 *s_connection;

    public:

        static void init();

        static void open(std::string filepath, std::string password, std::function<void(bool)> callback);

        static void error_callback(void *arg, int errorCode, const char *message);

        static void query(std::string query, std::function<void(std::shared_ptr<CSqliteStmt>)> callback);

    private:

        static std::vector<uint8_t> make_key(const std::string &password, bool *error);

        static void upgrade(int startVersion);

        static void drop_all_tables();

        static void create_all_tables();

    };

}