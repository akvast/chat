// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from concurrency.djinni

#include "CConcurrency.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol OCConcurrency;

namespace djinni_generated {

class CConcurrency
{
public:
    using CppType = std::shared_ptr<::generated::CConcurrency>;
    using CppOptType = std::shared_ptr<::generated::CConcurrency>;
    using ObjcType = id<OCConcurrency>;

    using Boxed = CConcurrency;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

