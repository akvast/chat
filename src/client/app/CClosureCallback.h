//
// Created by alexander on 25.02.18.
//

#pragma once

#include <functional>

#include "CCallback.hpp"

using namespace generated;

namespace client {

    class CClosureCallback
            : public CCallback {

        std::function<void()> _closure;

    public:

        explicit CClosureCallback(std::function<void()> closure);

        void execute() override;

    };

}