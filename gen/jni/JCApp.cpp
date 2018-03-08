// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from app.djinni

#include "JCApp.hpp"  // my header
#include "JCConcurrency.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

JCApp::JCApp() : ::djinni::JniInterface<::generated::CApp, JCApp>("com/github/akvast/securechat/CApp$CppProxy") {}

JCApp::~JCApp() = default;


CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::generated::CApp>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_com_github_akvast_securechat_CApp_instance(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::generated::CApp::instance();
        return ::djinni::release(::djinni_generated::JCApp::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setConcurrency(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_concurrency)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_concurrency(::djinni_generated::JCConcurrency::toCpp(jniEnv, j_concurrency));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setHost(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_host)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_host(::djinni::String::toCpp(jniEnv, j_host));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setPort(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jint j_port)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_port(::djinni::I32::toCpp(jniEnv, j_port));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setToken(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_token)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_token(::djinni::String::toCpp(jniEnv, j_token));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setName(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_name)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_name(::djinni::String::toCpp(jniEnv, j_name));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setEmail(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_email)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_email(::djinni::String::toCpp(jniEnv, j_email));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1setAvatarUrl(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_avatarUrl)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->set_avatar_url(::djinni::String::toCpp(jniEnv, j_avatarUrl));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1openDatabase(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->open_database(::djinni::String::toCpp(jniEnv, j_path));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT void JNICALL Java_com_github_akvast_securechat_CApp_00024CppProxy_native_1connect(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::generated::CApp>(nativeRef);
        ref->connect();
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

}  // namespace djinni_generated
