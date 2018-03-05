//
// Created by alexander on 03.03.18.
//

#include "CDialogsManager.h"

#include "CDatabase.h"
#include "CLog.h"

using namespace common;

namespace client {

    std::string CDialogsManager::get_drop_table_query() {
        return "DROP TABLE dialogs";
    }

    std::string CDialogsManager::get_create_table_query() {
        return "CREATE TABLE IF NOT EXISTS dialogs ("
                "  userId INT UNIQUE"
                ", title TEXT"
                ")";
    }

    void CDialogsManager::save(std::shared_ptr<CDialog> dialog) {
        auto query = "INSERT OR REPLACE INTO dialogs (userId, title) VALUES (?, ?)";

        CDatabase::query(query, [=](std::shared_ptr<CSqliteStmt> stmt) {
            stmt->bind_int64(dialog->userId);
            stmt->bind_string(dialog->title);
            stmt->execute();

            if (stmt->has_error()) {
                CLog::d("Can't save CDialog");
            }
        });
    }

    void CDialogsManager::get_all(std::function<void(std::vector<std::shared_ptr<CDialog>>)> callback) {
        auto query = "SELECT userId, title FROM dialogs";

        CDatabase::query(query, [=](std::shared_ptr<CSqliteStmt> stmt) {
            std::vector<std::shared_ptr<CDialog>> dialogs;
            while (auto reader = stmt->step()) {
                dialogs.emplace_back(parse(reader));
            }
            callback(dialogs);
        });
    }

    // Private:

    std::shared_ptr<CDialog> CDialogsManager::parse(std::shared_ptr<CSqliteReader> reader) {
        auto dialog = std::make_shared<CDialog>();
        dialog->userId = reader->get_int64();
        dialog->title = reader->get_string();
        return dialog;
    }

}