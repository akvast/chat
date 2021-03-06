// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_connection.djinni

#include "CConnectionViewModel.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class OCConnectionViewModel;

namespace djinni_generated {

class CConnectionViewModel
{
public:
    using CppType = std::shared_ptr<::generated::CConnectionViewModel>;
    using CppOptType = std::shared_ptr<::generated::CConnectionViewModel>;
    using ObjcType = OCConnectionViewModel*;

    using Boxed = CConnectionViewModel;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

