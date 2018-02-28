//
// Created by alexander on 28.02.18.
//

#pragma once

#include "CBaseViewModel.h"
#include "CDialogViewModel.hpp"

using namespace generated;

namespace client {

    class CDialogViewModelImpl
            : public CBaseViewModel,
              public CDialogViewModel,
              public std::enable_shared_from_this<CDialogViewModelImpl> {

        std::string _avatar;
        std::string _title;
        std::string _lastMessage;
        bool _isOnline;

    public:

        std::shared_ptr<CViewModel> get_base() override;

        void set_avatar(std::string avatar);

        std::string get_avatar() override;

        void set_title(std::string title);

        std::string get_title() override;

        void set_last_message(std::string lastMessage);

        std::string get_last_message() override;

        void set_is_online(bool isOnline);

        bool is_online() override;

    };

}