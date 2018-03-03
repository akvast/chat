//
// Created by alexander on 28.02.18.
//

#pragma once

#include "CBaseViewModel.h"
#include "CDialogViewModel.hpp"
#include "CDialog.h"

using namespace generated;

namespace client {

    class CDialogViewModelImpl
            : public CBaseViewModel,
              public CDialogViewModel,
              public std::enable_shared_from_this<CDialogViewModelImpl> {

        std::shared_ptr<CDialog> _dialog;

        std::string _avatar;
        std::string _lastMessage;
        bool _isOnline;

    public:

        explicit CDialogViewModelImpl(std::shared_ptr<CDialog> dialog);

        std::shared_ptr<CViewModel> get_base() override;

        void set_avatar(std::string avatar);

        std::string get_avatar() override;

        std::string get_title() override;

        void set_last_message(std::string lastMessage);

        std::string get_last_message() override;

        void set_is_online(bool isOnline);

        bool is_online() override;

    };

}