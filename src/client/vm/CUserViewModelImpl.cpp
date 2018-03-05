//
// Created by alexander on 05.03.18.
//

#include "CUserViewModelImpl.h"

namespace client {

    void CUserViewModelImpl::set_id(int64_t id) {
        _id = id;
    }

    void CUserViewModelImpl::set_name(std::string name) {
        _name = std::move(name);
    }

    std::shared_ptr<CViewModel> CUserViewModelImpl::get_base() {
        return shared_from_this();
    }

    std::string CUserViewModelImpl::get_avatar() {
        return "";
    }

    std::string CUserViewModelImpl::get_name() {
        return _name;
    }

    bool CUserViewModelImpl::is_online() {
        return false;
    }

}