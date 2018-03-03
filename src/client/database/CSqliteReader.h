//
// Created by alexander on 03.03.18.
//

#pragma once

#include <string>
#include "sqlite3.h"

namespace client {

    class CSqliteReader {

        sqlite3_stmt *_stmt;
        int _position;

    public:

        explicit CSqliteReader(sqlite3_stmt *stmt);

        int get_int();

        int64_t get_int64();

        std::string get_string();

    };

}