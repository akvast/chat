//
// Created by alexander on 25.02.18.
//

#include "CBaseViewModel.h"
#include "CViewModelListener.hpp"

namespace client {

    void CBaseViewModel::add_listener(const std::shared_ptr<CViewModelListener> &listener) {
        _lock.lock();
        _listeners.emplace_back(listener);
        _lock.unlock();
    }

    void CBaseViewModel::remove_listener(const std::shared_ptr<CViewModelListener> &listener) {
        _lock.lock();
        auto iter = _listeners.begin();
        while (iter != _listeners.end()) {
            if (*iter == listener) {
                _listeners.erase(iter);
                break;
            }
            iter++;
        }
        _lock.unlock();
    }

    void CBaseViewModel::notify() {
        _lock.lock();
        for (const auto &listener : _listeners) {
            listener->on_changed();
        }
        _lock.unlock();
    }

}