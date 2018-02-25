//
// Created by alexander on 25.02.18.
//

#pragma once

#include <vector>
#include <mutex>

#include "CViewModel.hpp"

using namespace generated;

namespace client {

    class CBaseViewModel
            : public CViewModel {

        std::vector<std::shared_ptr<CViewModelListener>> _listeners;
        std::mutex _lock;

    public:

        void add_listener(const std::shared_ptr<CViewModelListener> &listener) override;

        void remove_listener(const std::shared_ptr<CViewModelListener> &listener) override;

        void notify();

    };

}