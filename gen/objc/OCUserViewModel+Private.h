// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_user.djinni

#include "CUserViewModel.hpp"
#include <memory>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class OCUserViewModel;

namespace djinni_generated {

class CUserViewModel
{
public:
    using CppType = std::shared_ptr<::generated::CUserViewModel>;
    using CppOptType = std::shared_ptr<::generated::CUserViewModel>;
    using ObjcType = OCUserViewModel*;

    using Boxed = CUserViewModel;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCppOpt(const CppOptType& cpp);
    static ObjcType fromCpp(const CppType& cpp) { return fromCppOpt(cpp); }

private:
    class ObjcProxy;
};

}  // namespace djinni_generated

