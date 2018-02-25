// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from concurrency.djinni

#include "JCConcurrency.hpp"  // my header
#include "JCRunnable.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

JCConcurrency::JCConcurrency() : ::djinni::JniInterface<::generated::CConcurrency, JCConcurrency>("com/github/akvast/securechat/CConcurrency$CppProxy") {}

JCConcurrency::~JCConcurrency() = default;

JCConcurrency::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

JCConcurrency::JavaProxy::~JavaProxy() = default;

void JCConcurrency::JavaProxy::start_thread(const std::string & c_name, const std::shared_ptr<::generated::CRunnable> & c_runnable) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::JCConcurrency>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_startThread,
                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c_name)),
                           ::djinni::get(::djinni_generated::JCRunnable::fromCpp(jniEnv, c_runnable)));
    ::djinni::jniExceptionCheck(jniEnv);
}
void JCConcurrency::JavaProxy::execute_in_ui(const std::shared_ptr<::generated::CRunnable> & c_runnable) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::JCConcurrency>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_executeInUi,
                           ::djinni::get(::djinni_generated::JCRunnable::fromCpp(jniEnv, c_runnable)));
    ::djinni::jniExceptionCheck(jniEnv);
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CConcurrency_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::generated::CConcurrency>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CConcurrency_00024CppProxy_native_1startThread(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_name, jobject j_runnable)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CConcurrency>(nativeRef);
        ref->start_thread(::djinni::String::toCpp(jniEnv, j_name),
                          ::djinni_generated::JCRunnable::toCpp(jniEnv, j_runnable));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CConcurrency_00024CppProxy_native_1executeInUi(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_runnable)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CConcurrency>(nativeRef);
        ref->execute_in_ui(::djinni_generated::JCRunnable::toCpp(jniEnv, j_runnable));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
