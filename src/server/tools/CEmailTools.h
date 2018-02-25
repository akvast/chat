//
// Created by alexander on 25.02.18.
//

#pragma once

#include <string>

namespace server {

    class CEmailTools {

    public:

        static bool send(std::string from, std::string to, std::string subject, std::string message);

    };

}