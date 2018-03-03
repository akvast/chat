//
// Created by alexander on 03.03.18.
//

#include "CSqliteStmt.h"

#include "CLog.h"

using namespace common;

namespace client {

    CSqliteStmt::CSqliteStmt(sqlite3 *connection, std::string query)
            : _position(1),
              _hasError(false) {

        int result = sqlite3_prepare_v2(connection, query.c_str(), static_cast<int>(query.size()), &_stmt, nullptr);
        if (result != SQLITE_OK) {
            CLog::d("Can't prepare sqlite stmt: %s", query.c_str());
        }
    }

    CSqliteStmt::~CSqliteStmt() {
        sqlite3_free(_stmt);
    }

    void CSqliteStmt::bind_int(int value) {
        sqlite3_bind_int(_stmt, _position++, value);
    }

    void CSqliteStmt::bind_int64(int64_t value) {
        sqlite3_bind_int64(_stmt, _position++, value);
    }

    void CSqliteStmt::bind_string(const std::string &value) {
        sqlite3_bind_text(_stmt, _position++, value.data(), static_cast<int>(value.size()), nullptr);
    }

    bool CSqliteStmt::has_error() {
        return _hasError;
    }

    bool CSqliteStmt::execute() {
        _hasError = sqlite3_step(_stmt) == SQLITE_DONE;
        return _hasError;
    }

    std::shared_ptr<CSqliteReader> CSqliteStmt::step() {
        int result = sqlite3_step(_stmt);
        if (result == SQLITE_ROW) {
            return std::make_shared<CSqliteReader>(_stmt);
        } else {
            _hasError = result != SQLITE_DONE;
            return nullptr;
        }
    }

}