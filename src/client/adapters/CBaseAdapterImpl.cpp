//
// Created by alexander on 04.03.18.
//

#include "CBaseAdapterImpl.h"
#include "CAdapterListener.hpp"
#include "CAppImpl.h"

namespace client {

    void CBaseAdapterImpl::set_listener(const std::shared_ptr<CAdapterListener> &listener) {
        _listener = listener;
    }

    void CBaseAdapterImpl::reload() {

    }

    void CBaseAdapterImpl::notify_changed() const {
        auto listener = _listener;
        if (listener) {
            CAppImpl::instance()->execute_in_ui([=]() {
                listener->on_changed();
            });
        }
    }

}