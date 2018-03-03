//
// Created by alexander on 03.03.18.
//

#pragma once

#include <vector>
#include <memory>

#include "CDialog.h"
#include "CSqliteReader.h"

namespace client {

    class CDialogsManager {

    public:

        static std::string get_drop_table_query();

        static std::string get_create_table_query();

        static void save(std::shared_ptr<CDialog> dialog);

        static void get_all(std::function<void(std::vector<std::shared_ptr<CDialog>>)> callback);

    private:

        static std::shared_ptr<CDialog> parse(std::shared_ptr<CSqliteReader> reader);

    };

}