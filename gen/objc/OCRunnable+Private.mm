// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from common.djinni

#import "OCRunnable+Private.h"
#import "OCRunnable.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIObjcWrapperCache+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface OCRunnableCppProxy : NSObject<OCRunnable>

- (id)initWithCpp:(const std::shared_ptr<::generated::CRunnable>&)cppRef;

@end

@implementation OCRunnableCppProxy {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::generated::CRunnable>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::generated::CRunnable>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

- (void)run {
    try {
        _cppRefHandle.get()->run();
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

class CRunnable::ObjcProxy final
: public ::generated::CRunnable
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::CRunnable;
public:
    using ObjcProxyBase::ObjcProxyBase;
    void run() override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() run];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto CRunnable::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    if ([(id)objc isKindOfClass:[OCRunnableCppProxy class]]) {
        return ((OCRunnableCppProxy*)objc)->_cppRefHandle.get();
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto CRunnable::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    if (auto cppPtr = dynamic_cast<ObjcProxy*>(cpp.get())) {
        return cppPtr->djinni_private_get_proxied_objc_object();
    }
    return ::djinni::get_cpp_proxy<OCRunnableCppProxy>(cpp);
}

}  // namespace djinni_generated

@end
