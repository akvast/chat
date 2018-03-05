//
// Created by alexander on 24.02.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <cppconn/resultset.h>

#include "CUser.h"

class PUser;

namespace server {

    class CUsersManager {

    public:

        static void with_id(int32_t id, std::function<void(std::shared_ptr<CUser>)> callback);

        static void with_email(std::string email, std::function<void(std::shared_ptr<CUser>)> callback);

        static void search(const std::string &query, std::function<void(std::vector<PUser>)> callback);

    private:

        static std::shared_ptr<CUser> fetch(sql::ResultSet *resultSet);

    };

}