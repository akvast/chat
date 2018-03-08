//
// Created by alexander on 05.03.18.
//

#include "CUserViewModelImpl.h"
#include "CLog.h"

using namespace common;

namespace client {

    std::shared_ptr<CViewModel> CUserViewModelImpl::get_base() {
        return shared_from_this();
    }

    void CUserViewModelImpl::set_id(int64_t id) {
        _id = id;
    }

    void CUserViewModelImpl::set_name(std::string name) {
        _name = std::move(name);
    }

    std::string CUserViewModelImpl::get_name() {
        return _name;
    }

    void CUserViewModelImpl::set_email(std::string email) {
        _email = std::move(email);
    }

    std::string CUserViewModelImpl::get_email() {
        return _email;
    }

    void CUserViewModelImpl::set_avatar_url(std::string avatarUrl) {
        _avatarUrl = std::move(avatarUrl);
    }

    std::string CUserViewModelImpl::get_avatar() {
        return _avatarUrl;
    }

    bool CUserViewModelImpl::is_online() {
        return false;
    }

}