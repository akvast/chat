//
// Created by alexander on 03.03.18.
//

#pragma once

#include "CConcurrency.hpp"

using namespace generated;

namespace client {

    class CConcurrencyImpl
            : public CConcurrency {

    public:

        void start_thread(const std::string &name, const std::shared_ptr<CRunnable> &runnable) override;

        void execute_in_ui(const std::shared_ptr<CRunnable> &runnable) override;

    };

}