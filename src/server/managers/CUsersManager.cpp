//
// Created by alexander on 24.02.18.
//

#include "CUsersManager.h"

#include <cppconn/prepared_statement.h>

#include "CDatabase.h"
#include "network_structs.pb.h"

namespace server {

    void CUsersManager::auth(std::shared_ptr<PAuthMessage> message,
                             std::function<void(std::shared_ptr<CUser>)> callback) {

        CDatabase::execute([=](sql::Connection *connection) {
            auto updateStmt = connection->prepareStatement("INSERT INTO users (token, name, email, avatarUrl)"
                                                                   " VALUES (?, ?, ?, ?)"
                                                                   " ON DUPLICATE KEY UPDATE token = ?, name = ?, avatarUrl = ?");

            updateStmt->setString(1, message->token());
            updateStmt->setString(2, message->name());
            updateStmt->setString(3, message->email());
            updateStmt->setString(4, message->avatar_url());

            updateStmt->setString(5, message->token());
            updateStmt->setString(6, message->name());
            updateStmt->setString(7, message->avatar_url());

            updateStmt->execute();

            auto stmt = connection->prepareStatement("SELECT id, token, name, email, avatarUrl"
                                                             " FROM users"
                                                             " WHERE token = ?"
                                                             " LIMIT 1");
            stmt->setString(1, message->token());
            auto resultSet = stmt->executeQuery();

            if (resultSet->next()) {
                callback(fetch(resultSet));
            } else {
                callback(nullptr);
            }
        });
    }

    void CUsersManager::with_id(int32_t id, std::function<void(std::shared_ptr<CUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, token, name, email, avatarUrl"
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

    void CUsersManager::search(const std::string &query, std::function<void(std::vector<PUser>)> callback) {
        CDatabase::execute([=](sql::Connection *connection) {
            auto stmt = connection->prepareStatement("SELECT id, name, email, avatarUrl FROM users"
                                                             " WHERE name LIKE ?"
                                                             " OR email LIKE ?"
                                                             " LIMIT 20");

            stmt->setString(1, "%" + query + "%");
            stmt->setString(2, "%" + query + "%");
            auto resultSet = stmt->executeQuery();

            std::vector<PUser> userList;

            while (resultSet->next()) {
                auto user = PUser();
                user.set_id(resultSet->getInt64(1));
                user.set_name(resultSet->getString(2));
                user.set_email(resultSet->getString(3));
                user.set_avatar_url(resultSet->getString(4));
                userList.emplace_back(user);
            }

            callback(userList);
        });
    }

    // Private:

    std::shared_ptr<CUser> CUsersManager::fetch(sql::ResultSet *resultSet) {
        auto user = std::make_shared<CUser>();
        user->id = resultSet->getInt(1);
        user->token = resultSet->getString(2);
        user->name = resultSet->getString(3);
        user->email = resultSet->getString(4);
        user->avatarUrl = resultSet->getString(5);
        return user;
    }

}