//
// Created by alexander on 24.02.18.
//

#pragma once

#include <cstdint>
#include <string>

namespace common {

    class CUser {

        int32_t _id;
        std::string _login;
        std::string _password;
        std::string _name;

    public:

        explicit CUser();

        void set_id(int32_t id);

        int32_t get_id() const;

        void set_login(std::string login);

        std::string get_login() const;

        void set_password(std::string password);

        std::string get_password() const;

        void set_name(std::string name);

        std::string get_name() const;

    };

}