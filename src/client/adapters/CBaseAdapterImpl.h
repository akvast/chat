//
// Created by alexander on 04.03.18.
//

#pragma once

#include "CBaseAdapter.hpp"

using namespace generated;

namespace client {

    class CBaseAdapterImpl
            : public CBaseAdapter {

        std::shared_ptr<CAdapterListener> _listener;

    public:

        void set_listener(const std::shared_ptr<CAdapterListener> &listener) override;

        void reload() override;

        void notify_changed() const;

    };

}