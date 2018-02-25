//
// Created by alexander on 25.02.18.
//

#pragma once

#include "CConnection.h"
#include "CBaseViewModel.h"
#include "CConnectionViewModel.hpp"
#include "IConnectionListener.h"

using namespace generated;

namespace client {

    class CConnectionViewModelImpl
            : public CBaseViewModel,
              public CConnectionViewModel,
              public IConnectionListener,
              public std::enable_shared_from_this<CConnectionViewModelImpl> {

        std::shared_ptr<CConnection> _connection;

        std::atomic_bool _isAuthFailed;

    public:

        static std::shared_ptr<CConnectionViewModelImpl> instance();

        explicit CConnectionViewModelImpl();

        std::shared_ptr<CViewModel> get_base() override;

        bool is_connected() override;

        bool is_connecting() override;

        bool is_auth_failed() override;

        // IConnectionListener:

        void on_state_changed() override;

    private:

        void init();

    };

}