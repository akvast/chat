//
// Created by alexander on 23.02.18.
//

#include "CLog.h"

namespace common {

    void CLog::d(const std::string &message) {
        printf(message.c_str());
        printf("\n");
    }

}