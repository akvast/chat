//
// Created by alexander on 24.02.18.
//

#include "CDatabase.h"

#include "CLog.h"
#include <cppconn/prepared_statement.h>

using namespace common;

namespace server {

    std::shared_ptr<boost::asio::io_service> CDatabase::s_ioService;

    sql::Connection *CDatabase::s_connection;

    void CDatabase::init(std::shared_ptr<boost::asio::io_service> ioService) {
        s_ioService = std::move(ioService);
    }

    void CDatabase::connect(std::string host, std::string user, std::string password, std::string database) {
        s_ioService->post([=]() {

            sql::ConnectOptionsMap connectionProperties;

            connectionProperties["hostName"] = host;
            connectionProperties["port"] = 3306;

            connectionProperties["userName"] = user;
            connectionProperties["password"] = password;
            connectionProperties["schema"] = database;
            connectionProperties["OPT_RECONNECT"] = true;

            auto driver = sql::mysql::get_driver_instance();
            s_connection = driver->connect(connectionProperties);

            if (s_connection->isValid()) {
                CLog::d("Connected to MySQL server " + host + " : " + database);
            } else {
                CLog::d("Can't connect to MySQL server " + host + " : " + database);
                return;
            }

            s_connection->setClientOption("OPT_CHARSET_NAME", "utf8");
        });
    }

    void CDatabase::execute(std::function<void(sql::Connection *connection)> func) {
        s_ioService->post([=]() {
            func(s_connection);
        });
    }

}