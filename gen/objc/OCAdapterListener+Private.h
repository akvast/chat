// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adapter_base.djinni

#include "CAdapterListener.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@protocol OCAdapterListener;

namespace djinni_generated {

class CAdapterListener
{
public:
    using CppType = std::shared_ptr<::generated::CAdapterListener>;
    using CppOptType = std::shared_ptr<::generated::CAdapterListener>;
    using ObjcType = id<OCAdapterListener>;

    using Boxed = CAdapterListener;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

