//
// Created by alexander on 05.03.18.
//

#pragma once

#include "CBaseViewModel.h"
#include "CUserViewModel.hpp"

using namespace generated;

namespace client {

    class CUserViewModelImpl
            : public CBaseViewModel,
              public CUserViewModel,
              public std::enable_shared_from_this<CUserViewModelImpl> {

        int64_t _id;
        std::string _name;
        std::string _email;
        std::string _avatarUrl;

    public:

        std::shared_ptr<CViewModel> get_base() override;

        void set_id(int64_t id);

        void set_name(std::string name);

        std::string get_name() override;

        void set_email(std::string email);

        std::string get_email() override;

        void set_avatar_url(std::string avatarUrl);

        std::string get_avatar() override;

        bool is_online() override;

    };

}