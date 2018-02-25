//
// Created by alexander on 24.02.18.
//

#include "CUsersManager.h"
#include "CDatabase.h"

#include <cppconn/prepared_statement.h>

namespace server {

    void CUsersManager::with_id(int32_t id, std::function<void(std::shared_ptr<CUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, email, isVerified, verifyKey, password, name"
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

    void CUsersManager::with_email(std::string email, std::function<void(std::shared_ptr<CUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, email, isVerified, verifyKey, password, name"
                                                             " FROM users"
                                                             " WHERE email = ?"
                                                             " LIMIT 1");
            stmt->setString(1, email);
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
        user->id = resultSet->getInt(1);
        user->email = resultSet->getString(2);
        user->isVerified = resultSet->getBoolean(3);
        user->verifyKey = static_cast<int16_t>(resultSet->getInt(4));
        user->password = resultSet->getString(5);
        user->name = resultSet->getString(6);
        return user;
    }

}