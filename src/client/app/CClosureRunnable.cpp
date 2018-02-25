//
// Created by alexander on 25.02.18.
//

#include "CClosureRunnable.h"

#include <utility>

namespace client {

    CClosureRunnable::CClosureRunnable(std::function<void()> closure)
            : _closure(std::move(closure)) {

    }

    void CClosureRunnable::run() {
        _closure();
    }

}