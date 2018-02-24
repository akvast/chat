//
// Created by alexander on 24.02.18.
//

#include "CUsersManager.h"
#include "CDatabase.h"

#include <cppconn/prepared_statement.h>

namespace server {

    void CUsersManager::with_id(int32_t id, std::function<void(std::shared_ptr<CUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, login, password, name"
                                                             " FROM users"
                                                             " WHERE id = ?"
                                                             " LIMIT 1");
            stmt->setInt(1, id);
            auto resultSet = stmt->executeQuery();

            if (resultSet->next()) {
                callback(fetch(resultSet));
            } else {
                callback(nullptr);
            }
        });
    }

    void CUsersManager::with_login(std::string login, std::function<void(std::shared_ptr<CUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, login, password, name"
                                                             " FROM users"
                                                             " WHERE login = ?"
                                                             " LIMIT 1");
            stmt->setString(1, login);
            auto resultSet = stmt->executeQuery();

            if (resultSet->next()) {
                callback(fetch(resultSet));
            } else {
                callback(nullptr);
            }
        });
    }

    std::shared_ptr<CUser> CUsersManager::fetch(sql::ResultSet *resultSet) {
        auto user = std::make_shared<CUser>();
        user->set_id(resultSet->getInt(1));
        user->set_login(resultSet->getString(2));
        user->set_password(resultSet->getString(3));
        user->set_name(resultSet->getString(4));
        return user;
    }

}