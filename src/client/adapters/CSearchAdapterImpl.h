//
// Created by alexander on 05.03.18.
//

#pragma once

#include "CBaseAdapterImpl.h"
#include "CSearchAdapter.hpp"
#include "network.pb.h"

using namespace generated;

namespace client {

    class CSearchAdapterImpl
            : public CBaseAdapterImpl,
              public CSearchAdapter,
              public std::enable_shared_from_this<CSearchAdapterImpl> {

        std::vector<std::shared_ptr<CUserViewModel>> _users;

    public:

        static std::shared_ptr<CSearchAdapterImpl> instance();

        void init();

        std::shared_ptr<CBaseAdapter> get_base() override;

        void set_search_query(const std::string &query) override;

        std::vector<std::shared_ptr<CUserViewModel>> get_users() override;

        void on_search_response(std::shared_ptr<PContactsSearchResponse> response);

    };

}