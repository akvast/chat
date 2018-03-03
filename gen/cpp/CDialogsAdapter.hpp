// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adapter_dialogs.djinni

#pragma once

#include <memory>
#include <vector>

namespace generated {

class CBaseAdapter;
class CDialogViewModel;

class CDialogsAdapter {
public:
    virtual ~CDialogsAdapter() {}

    static std::shared_ptr<CDialogsAdapter> instance();

    virtual std::shared_ptr<CBaseAdapter> get_base() = 0;

    virtual std::vector<std::shared_ptr<CDialogViewModel>> get_dialogs() = 0;
};

}  // namespace generated
