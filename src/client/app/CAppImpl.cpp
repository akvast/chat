//
// Created by alexander on 25.02.18.
//

#include "CAppImpl.h"

namespace generated {

    std::shared_ptr<CApp> CApp::instance() {
        return client::CAppImpl::instance();
    }

}

namespace client {

    std::shared_ptr<CAppImpl> CAppImpl::instance() {
        static auto s_instance = std::make_shared<CAppImpl>();
        return s_instance;
    }

    void CAppImpl::set_multithread_support(const std::shared_ptr<CMultithreadSupport> &multithread_support) {
        _multithread = multithread_support;
    }

    void CAppImpl::connect(const std::string &host, int32_t port) {

    }

}