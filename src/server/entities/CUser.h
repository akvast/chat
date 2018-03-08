//
// Created by alexander on 24.02.18.
//

#pragma once

#include <cstdint>
#include <string>

namespace server {

    struct CUser {

        int32_t id;
        std::string token;
        std::string name;
        std::string email;
        std::string avatarUrl;
    };

}