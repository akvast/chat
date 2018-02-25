// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from app.djinni

#pragma once

#include "../cpp/CApp.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class JCApp final : ::djinni::JniInterface<::generated::CApp, JCApp> {
public:
    using CppType = std::shared_ptr<::generated::CApp>;
    using CppOptType = std::shared_ptr<::generated::CApp>;
    using JniType = jobject;

    using Boxed = JCApp;

    ~JCApp();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<JCApp>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<JCApp>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    JCApp();
    friend ::djinni::JniClass<JCApp>;
    friend ::djinni::JniInterface<::generated::CApp, JCApp>;

};

}  // namespace djinni_generated
