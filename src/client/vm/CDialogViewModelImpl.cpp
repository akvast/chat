//
// Created by alexander on 28.02.18.
//

#include "CDialogViewModelImpl.h"

namespace client {

    CDialogViewModelImpl::CDialogViewModelImpl(std::shared_ptr<CDialog> dialog)
            : _dialog(std::move(dialog)) {

    }

    std::shared_ptr<CViewModel> CDialogViewModelImpl::get_base() {
        return shared_from_this();
    }

    void CDialogViewModelImpl::set_avatar(std::string avatar) {
        _avatar = std::move(avatar);
    }

    std::string CDialogViewModelImpl::get_avatar() {
        return _avatar;
    }

    std::string CDialogViewModelImpl::get_title() {
        return _dialog->title;
    }

    void CDialogViewModelImpl::set_last_message(std::string lastMessage) {
        _lastMessage = std::move(lastMessage);
    }

    std::string CDialogViewModelImpl::get_last_message() {
        return _lastMessage;
    }

    void CDialogViewModelImpl::set_is_online(bool isOnline) {
        _isOnline = isOnline;
    }

    bool CDialogViewModelImpl::is_online() {
        return _isOnline;
    }

}