//
// Created by alexander on 28.02.18.
//

#pragma once

#include "CDialogsAdapter.hpp"

using namespace generated;

namespace client {

    class CDialogsAdapterImpl
            : public CDialogsAdapter,
              public std::enable_shared_from_this<CDialogsAdapterImpl> {

    public:

        static std::shared_ptr<CDialogsAdapter> instance();

        std::vector<std::shared_ptr<CDialogViewModel>> get_dialogs() override;

    };

}