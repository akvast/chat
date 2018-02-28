//
// Created by alexander on 28.02.18.
//

#include <sstream>

#include "CDialogsAdapterImpl.h"
#include "CDialogViewModelImpl.h"

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
        }
        return s_instance;
    }

    std::vector<std::shared_ptr<CDialogViewModel>> CDialogsAdapterImpl::get_dialogs() {
        std::vector<std::shared_ptr<CDialogViewModel>> testData;

        for (int i = 0; i < 50; ++i) {
            std::ostringstream titleBuilder;
            std::ostringstream lastMessageBuilder;

            titleBuilder << "Dialog " << i;
            lastMessageBuilder << "Last message " << i;

            auto dialog = std::make_shared<CDialogViewModelImpl>();
            dialog->set_title(titleBuilder.str());
            dialog->set_last_message(lastMessageBuilder.str());
            testData.emplace_back(dialog);
        }

        return testData;
    }

}