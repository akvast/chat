//
// Created by alexander on 05.03.18.
//

#include "CSearchAdapterImpl.h"
#include "CUserViewModelImpl.h"
#include "CConnection.h"
#include "CLog.h"

namespace generated {

    std::shared_ptr<CSearchAdapter> CSearchAdapter::instance() {
        return client::CSearchAdapterImpl::instance();
    }

}

namespace client {

    std::shared_ptr<CSearchAdapterImpl> CSearchAdapterImpl::instance() {
        static std::shared_ptr<CSearchAdapterImpl> s_instance;
        if (!s_instance) {
            s_instance = std::make_shared<CSearchAdapterImpl>();
            s_instance->init();
        }
        return s_instance;
    }

    void CSearchAdapterImpl::init() {

    }

    std::shared_ptr<CBaseAdapter> CSearchAdapterImpl::get_base() {
        return shared_from_this();
    }

    void CSearchAdapterImpl::set_search_query(const std::string &query) {
        CConnection::instance()->get_handler()->send_contacts_search(1, query);
    }

    std::vector<std::shared_ptr<CUserViewModel>> CSearchAdapterImpl::get_users() {
        return _users;
    }

    void CSearchAdapterImpl::on_search_response(std::shared_ptr<PContactsSearchResponse> response) {
        _users.clear();
        for (int i = 0; i < response->users_size(); ++i) {
            const auto &user = response->users(i);

            auto vm = std::make_shared<CUserViewModelImpl>();
            vm->set_id(user.id());
            vm->set_name(user.name());
            vm->set_email(user.email());
            vm->set_avatar_url(user.avatar_url());
            _users.emplace_back(vm);
        }
        notify_changed();
    }

}