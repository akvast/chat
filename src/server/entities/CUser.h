//
// Created by alexander on 24.02.18.
//

#pragma once

#include <cstdint>
#include <string>

namespace server {

    struct CUser {

        int32_t id;
        std::string email;
        bool  isVerified;
        int16_t verifyKey;
        std::string password;
        std::string name;
    };

}