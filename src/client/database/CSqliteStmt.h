//
// Created by alexander on 03.03.18.
//

#pragma once

#include <string>
#include <memory>
#include "sqlite3.h"
#include "CSqliteReader.h"

namespace client {

    class CSqliteStmt {

        sqlite3_stmt *_stmt;
        int _position;

        bool _hasError;

    public:

        explicit CSqliteStmt(sqlite3 *connection, std::string query);

        ~CSqliteStmt();

        void bind_int(int value);

        void bind_int64(int64_t value);

        void bind_string(const std::string &value);

        bool has_error();

        bool execute();

        std::shared_ptr<CSqliteReader> step();

    };

}