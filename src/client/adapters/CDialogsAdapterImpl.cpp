//
// Created by alexander on 28.02.18.
//

#include <sstream>

#include "CDialogsAdapterImpl.h"
#include "CDialogViewModelImpl.h"
#include "CDialogsManager.h"

namespace generated {

    std::shared_ptr<CDialogsAdapter> CDialogsAdapter::instance() {
        return client::CDialogsAdapterImpl::instance();
    }

}

namespace client {

    std::shared_ptr<CDialogsAdapter> CDialogsAdapterImpl::instance() {
        static std::shared_ptr<CDialogsAdapterImpl> s_instance;
        if (!s_instance) {
            s_instance = std::make_shared<CDialogsAdapterImpl>();
            s_instance->reload();
        }
        return s_instance;
    }

    void CDialogsAdapterImpl::reload() {
        auto self = shared_from_this();
        CDialogsManager::get_all([self](std::vector<std::shared_ptr<CDialog>> dialogs) {
            self->_dialogs.clear();
            for (const auto &dialog : dialogs) {
                self->_dialogs.emplace_back(std::make_shared<CDialogViewModelImpl>(dialog));
            }
            self->notify_changed();
        });
    }

    std::shared_ptr<CBaseAdapter> CDialogsAdapterImpl::get_base() {
        return shared_from_this();
    }

    std::vector<std::shared_ptr<CDialogViewModel>> CDialogsAdapterImpl::get_dialogs() {
        return _dialogs;
    }

}