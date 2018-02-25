//
// Created by alexander on 23.02.18.
//

#pragma once

#include <string>
#include <mutex>

#ifdef ANDROID
#include <android/log.h>
#endif

namespace common {

    class CLog {

        static std::mutex s_logMutex;

    public:

        template<typename... Args>
        static void d(const std::string &format, Args... args) {
#ifdef ANDROID
            __android_log_print(ANDROID_LOG_DEBUG  , "Native", format.c_str(), args...);
#else
            s_logMutex.lock();
            printf(format.c_str(), args...);
            printf("\n");
            s_logMutex.unlock();
#endif
        }

    };

}