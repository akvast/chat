// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_dialog.djinni

#pragma once

#include <memory>
#include <string>

namespace generated {

class CViewModel;

class CDialogViewModel {
public:
    virtual ~CDialogViewModel() {}

    virtual std::shared_ptr<CViewModel> get_base() = 0;

    virtual std::string get_avatar() = 0;

    virtual std::string get_title() = 0;

    virtual std::string get_last_message() = 0;

    virtual bool is_online() = 0;
};

}  // namespace generated
