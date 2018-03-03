// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from adapter_base.djinni

#pragma once

#include "../cpp/CAdapterListener.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class JCAdapterListener final : ::djinni::JniInterface<::generated::CAdapterListener, JCAdapterListener> {
public:
    using CppType = std::shared_ptr<::generated::CAdapterListener>;
    using CppOptType = std::shared_ptr<::generated::CAdapterListener>;
    using JniType = jobject;

    using Boxed = JCAdapterListener;

    ~JCAdapterListener();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<JCAdapterListener>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<JCAdapterListener>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    JCAdapterListener();
    friend ::djinni::JniClass<JCAdapterListener>;
    friend ::djinni::JniInterface<::generated::CAdapterListener, JCAdapterListener>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::generated::CAdapterListener
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void on_changed() override;

    private:
        friend ::djinni::JniInterface<::generated::CAdapterListener, ::djinni_generated::JCAdapterListener>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/github/akvast/securechat/CAdapterListener") };
    const jmethodID method_onChanged { ::djinni::jniGetMethodID(clazz.get(), "onChanged", "()V") };
};

}  // namespace djinni_generated
