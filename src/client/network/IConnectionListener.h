//
// Created by alexander on 25.02.18.
//

#pragma once

namespace client {

    class IConnectionListener {

    public:

        virtual void on_state_changed() = 0;

    };

}