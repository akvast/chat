//
// Created by alexander on 25.02.18.
//

#pragma once

#include "CApp.hpp"
#include "CMultithreadSupport.hpp"

using namespace generated;

namespace client {

    class CAppImpl
            : public CApp {

        std::shared_ptr<CMultithreadSupport> _multithread;

    public:

        static std::shared_ptr<CAppImpl> instance();

        void set_multithread_support(const std::shared_ptr<CMultithreadSupport> &multithread_support) override;

        void connect(const std::string &host, int32_t port) override;

    };

}