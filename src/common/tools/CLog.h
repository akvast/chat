//
// Created by alexander on 23.02.18.
//

#pragma once

#include <string>
#include <mutex>

namespace common {

    class CLog {

        static std::mutex s_logMutex;

    public:

        template<typename... Args>
        static void d(const std::string &format, Args... args) {
            s_logMutex.lock();
            printf(format.c_str(), args...);
            printf("\n");
            s_logMutex.unlock();
        }

    };

}