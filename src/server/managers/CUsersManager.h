//
// Created by alexander on 24.02.18.
//

#pragma once

#include <cstdint>
#include <memory>
#include <cppconn/resultset.h>

#include "CUser.h"

using namespace common;

namespace server {

    class CUsersManager {

    public:

        static void with_id(int32_t id, std::function<void(std::shared_ptr<CUser>)> callback);

        static void with_login(std::string login, std::function<void(std::shared_ptr<CUser>)> callback);

    private:

        static std::shared_ptr<CUser> fetch(sql::ResultSet *resultSet);

    };

}