//
// Created by alexander on 24.02.18.
//

#include "CUser.h"

namespace common {

    CUser::CUser() = default;

    void CUser::set_id(int32_t id) {
        _id = id;
    }

    int32_t CUser::get_id() const {
        return _id;
    }

    void CUser::set_login(std::string login) {
        _login = std::move(login);
    }

    std::string CUser::get_login() const {
        return _login;
    }

    void CUser::set_password(std::string password) {
        _password = std::move(password);
    }

    std::string CUser::get_password() const {
        return _password;
    }

    void CUser::set_name(std::string name) {
        _name = std::move(name);
    }

    std::string CUser::get_name() const {
        return _name;
    }

}