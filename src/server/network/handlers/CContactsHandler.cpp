//
// Created by alexander on 05.03.18.
//

#include "CContactsHandler.h"
#include "CUsersManager.h"

#include "network.pb.h"

namespace server {

    CClientState CContactsHandler::get_required_state() {
        return CClientState::Authorized;
    }

    std::vector<COpCode> CContactsHandler::get_observable_op_codes() {
        return {
                COpCode::ContactsSearch
        };
    }

    void CContactsHandler::handle(COpCode opCode, std::shared_ptr<CMessage> message) {
        switch (opCode) {
            case COpCode::ContactsSearch:
                handle_contacts_search(message);
                break;
            default:
                break;
        }
    }

    // Private:

    void CContactsHandler::handle_contacts_search(std::shared_ptr<CMessage> message) {
        auto searchRequest = parse<PContactsSearchRequest>(message);
        auto self = shared_from_this();

        CUsersManager::search(searchRequest->query(), [=](std::vector<PUser> userList) {
            auto response = std::make_shared<PContactsSearchResponse>();
            response->set_request_id(searchRequest->request_id());

            google::protobuf::RepeatedPtrField<PUser> userRepeatedField(userList.begin(), userList.end());
            response->mutable_users()->Swap(&userRepeatedField);

            self->send(COpCode::ContactsSearchResult, response);
        });
    }

}