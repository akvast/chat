//
// Created by alexander on 25.02.18.
//

#pragma once

#include <functional>

#include "CRunnable.hpp"

using namespace generated;

namespace client {

    class CClosureRunnable
            : public CRunnable {

        std::function<void()> _closure;

    public:

        explicit CClosureRunnable(std::function<void()> closure);

        void run() override;

    };

}