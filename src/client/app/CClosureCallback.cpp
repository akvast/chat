//
// Created by alexander on 25.02.18.
//

#include "CClosureCallback.h"

#include <utility>

namespace client {

    CClosureCallback::CClosureCallback(std::function<void()> closure)
            : _closure(std::move(closure)) {

    }

    void CClosureCallback::execute() {
        _closure();
    }

}