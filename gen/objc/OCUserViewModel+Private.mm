// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_user.djinni

#import "OCUserViewModel+Private.h"
#import "OCUserViewModel.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "OCViewModel+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface OCUserViewModel ()

- (id)initWithCpp:(const std::shared_ptr<::generated::CUserViewModel>&)cppRef;

@end

@implementation OCUserViewModel {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::generated::CUserViewModel>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::generated::CUserViewModel>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (nullable OCViewModel *)getBase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_base();
        return ::djinni_generated::CViewModel::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getName {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_name();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getEmail {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_email();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getAvatar {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_avatar();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isOnline {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->is_online();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto CUserViewModel::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto CUserViewModel::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<OCUserViewModel>(cpp);
}

}  // namespace djinni_generated

@end
