// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adapter_search.djinni

#include "CSearchAdapter.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class OCSearchAdapter;

namespace djinni_generated {

class CSearchAdapter
{
public:
    using CppType = std::shared_ptr<::generated::CSearchAdapter>;
    using CppOptType = std::shared_ptr<::generated::CSearchAdapter>;
    using ObjcType = OCSearchAdapter*;

    using Boxed = CSearchAdapter;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated
