// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_user.djinni

#include "JCUserViewModel.hpp"  // my header
#include "JCViewModel.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

JCUserViewModel::JCUserViewModel() : ::djinni::JniInterface<::generated::CUserViewModel, JCUserViewModel>("com/github/akvast/securechat/CUserViewModel$CppProxy") {}

JCUserViewModel::~JCUserViewModel() = default;


CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::generated::CUserViewModel>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_native_1getBase(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CUserViewModel>(nativeRef);
        auto r = ref->get_base();
        return ::djinni::release(::djinni_generated::JCViewModel::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_native_1getName(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CUserViewModel>(nativeRef);
        auto r = ref->get_name();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_native_1getEmail(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CUserViewModel>(nativeRef);
        auto r = ref->get_email();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_native_1getAvatar(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CUserViewModel>(nativeRef);
        auto r = ref->get_avatar();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jboolean JNICALL Java_com_github_akvast_securechat_CUserViewModel_00024CppProxy_native_1isOnline(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CUserViewModel>(nativeRef);
        auto r = ref->is_online();
        return ::djinni::release(::djinni::Bool::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
