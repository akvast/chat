//
// Created by alexander on 03.03.18.
//

#include "CDatabase.h"

#include <openssl/evp.h>

#include "CLog.h"
#include "CAppImpl.h"

#include "CDialogsManager.h"

#define DATABASE_VERSION 2

using namespace common;

namespace client {

    std::shared_ptr<boost::asio::io_service> CDatabase::s_ioService;
    std::shared_ptr<boost::asio::io_service::work> CDatabase::s_worker;

    sqlite3 *CDatabase::s_connection;

    void CDatabase::init() {
        s_ioService = std::make_shared<boost::asio::io_service>();
        s_worker = std::make_shared<boost::asio::io_service::work>(*s_ioService);

        CAppImpl::instance()->start_thread("Database", []() {
            s_ioService->run();
        });
    }

    void CDatabase::open(std::string filepath,
                         std::string password,
                         std::function<void(bool)> callback) {

        s_ioService->post([=]() {
            int result = sqlite3_open(filepath.c_str(), &s_connection);
            if (result != SQLITE_OK) {
                CLog::d("Can't open database: %s", filepath.c_str());
                callback(false);
                return;
            }

            // Set error callback:
            sqlite3_config(SQLITE_CONFIG_LOG, CDatabase::error_callback, nullptr);

            bool hasError;
            auto key = make_key(password, &hasError);
            if (hasError) {
                callback(false);
                return;
            }

            // TODO: Enable encryption
//            sqlite3_key(s_connection, key.data(), 32);

            CSqliteStmt(s_connection, "CREATE TABLE IF NOT EXISTS database_version (version INT)").execute();

            auto versionStmt = CSqliteStmt(s_connection, "SELECT * FROM database_version");
            auto versionReader = versionStmt.step();

            if (versionStmt.has_error()) {
                CLog::d("Can't decrypt database.");
                callback(false);
                return;
            }

            if (versionReader) {
                auto version = versionReader->get_int();
                CLog::d("Database version: %zu", (size_t) version);
                if (version != DATABASE_VERSION)
                    upgrade(version);
                auto insertStmt = CSqliteStmt(s_connection, "UPDATE database_version SET version = ?");
                insertStmt.bind_int(DATABASE_VERSION);
                insertStmt.execute();
            } else {
                auto insertStmt = CSqliteStmt(s_connection, "INSERT INTO database_version (version) VALUES (?)");
                insertStmt.bind_int(DATABASE_VERSION);
                insertStmt.execute();
                CLog::d("New database.");
                create_all_tables();
            }

            callback(true);
        });
    }

    void CDatabase::error_callback(void *arg, int errorCode, const char *message) {
        CLog::d("(%d) %s", errorCode, message);
    }

    void CDatabase::query(std::string query, std::function<void(std::shared_ptr<CSqliteStmt>)> callback) {
        s_ioService->post([=]() {
            callback(std::make_shared<CSqliteStmt>(s_connection, query));
        });
    }

    // Private:

    std::vector<uint8_t> CDatabase::make_key(const std::string &password, bool *error) {
        auto key = std::vector<uint8_t>();
        key.resize(32);

        auto result = PKCS5_PBKDF2_HMAC_SHA1(password.data(),
                                             static_cast<int>(password.size()),
                                             nullptr,
                                             0,
                                             100,
                                             32,
                                             key.data());

        if (result != 1) {
            CLog::d("Can't generate PKCS key from password.");
            *error = true;
            return key;
        }

        *error = false;
        return key;
    }

    void CDatabase::upgrade(int startVersion) {
        CLog::d("CDatabase::upgrade from %d", startVersion);

        // TODO: Migration

        drop_all_tables();
        create_all_tables();
    }

    void CDatabase::drop_all_tables() {
        CLog::d("CDatabase::drop_all_tables");

        CSqliteStmt(s_connection, CDialogsManager::get_drop_table_query()).execute();
    }

    void CDatabase::create_all_tables() {
        CLog::d("CDatabase::create_all_tables");

        CSqliteStmt(s_connection, CDialogsManager::get_create_table_query()).execute();
    }

}