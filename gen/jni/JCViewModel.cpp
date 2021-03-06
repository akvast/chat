// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vm_base.djinni

#include "JCViewModel.hpp"  // my header
#include "JCViewModelListener.hpp"

namespace djinni_generated {

JCViewModel::JCViewModel() : ::djinni::JniInterface<::generated::CViewModel, JCViewModel>("com/github/akvast/securechat/CViewModel$CppProxy") {}

JCViewModel::~JCViewModel() = default;


CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CViewModel_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::generated::CViewModel>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CViewModel_00024CppProxy_native_1addListener(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CViewModel>(nativeRef);
        ref->add_listener(::djinni_generated::JCViewModelListener::toCpp(jniEnv, j_listener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CViewModel_00024CppProxy_native_1removeListener(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_listener)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CViewModel>(nativeRef);
        ref->remove_listener(::djinni_generated::JCViewModelListener::toCpp(jniEnv, j_listener));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
