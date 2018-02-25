// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_connection.djinni

#import "OCConnectionViewModel+Private.h"
#import "OCConnectionViewModel.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "OCViewModel+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface OCConnectionViewModel ()

- (id)initWithCpp:(const std::shared_ptr<::generated::CConnectionViewModel>&)cppRef;

@end

@implementation OCConnectionViewModel {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::generated::CConnectionViewModel>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::generated::CConnectionViewModel>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable OCConnectionViewModel *)instance {
    try {
        auto objcpp_result_ = ::generated::CConnectionViewModel::instance();
        return ::djinni_generated::CConnectionViewModel::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nullable OCViewModel *)getBase {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_base();
        return ::djinni_generated::CViewModel::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isConnected {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->is_connected();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isConnecting {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->is_connecting();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)isAuthFailed {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->is_auth_failed();
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto CConnectionViewModel::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto CConnectionViewModel::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<OCConnectionViewModel>(cpp);
}

}  // namespace djinni_generated

@end