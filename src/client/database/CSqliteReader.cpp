//
// Created by alexander on 03.03.18.
//

#include "CSqliteReader.h"

#include "CLog.h"

using namespace common;

namespace client {

    CSqliteReader::CSqliteReader(sqlite3_stmt *stmt)
            : _position(0),
              _stmt(stmt) {

    }

    int CSqliteReader::get_int() {
        return sqlite3_column_int(_stmt, _position++);
    }

    int64_t CSqliteReader::get_int64() {
        return sqlite3_column_int64(_stmt, _position++);
    }

    std::string CSqliteReader::get_string() {
        auto text = sqlite3_column_text(_stmt, _position++);
        CLog::d("CSqliteReader::get_string : %s", text);
        auto result = std::string(reinterpret_cast<const char*>(text));
        return result;
    }

}