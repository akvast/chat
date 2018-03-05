//
// Created by alexander on 24.02.18.
//

#include "CUsersManager.h"

#include <cppconn/prepared_statement.h>

#include "CDatabase.h"
#include "network_structs.pb.h"

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

    void CUsersManager::search(const std::string &query, std::function<void(std::vector<PUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, name FROM users WHERE name LIKE ? LIMIT 20");

            stmt->setString(1, "%" + query + "%");
            auto resultSet = stmt->executeQuery();

            std::vector<PUser> userList;

            while (resultSet->next()) {
                auto user = PUser();
                user.set_id(resultSet->getInt64(1));
                user.set_name(resultSet->getString(2));
                userList.emplace_back(user);
            }

            callback(userList);
        });
    }

    // Private:

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