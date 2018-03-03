//
// Created by alexander on 28.02.18.
//

#pragma once

#include <mutex>
#include "CBaseAdapterImpl.h"
#include "CDialogsAdapter.hpp"

using namespace generated;

namespace client {

    class CDialogsAdapterImpl
            : public CBaseAdapterImpl,
              public CDialogsAdapter,
              public std::enable_shared_from_this<CDialogsAdapterImpl> {

        std::vector<std::shared_ptr<CDialogViewModel>> _dialogs;

    public:

        static std::shared_ptr<CDialogsAdapter> instance();

        void reload() override;

        std::shared_ptr<CBaseAdapter> get_base() override;

        std::vector<std::shared_ptr<CDialogViewModel>> get_dialogs() override;

    };

}