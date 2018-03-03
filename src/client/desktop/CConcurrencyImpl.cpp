//
// Created by alexander on 03.03.18.
//

#include "CConcurrencyImpl.h"

#include <thread>
#include "CRunnable.hpp"

namespace client {

    void CConcurrencyImpl::start_thread(const std::string &name, const std::shared_ptr<CRunnable> &runnable) {
        std::thread([=]() {
            runnable->run();
        }).detach();
    }

    void CConcurrencyImpl::execute_in_ui(const std::shared_ptr<CRunnable> &runnable) {
        // TODO:
        runnable->run();
    }

}