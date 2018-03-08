//
// Created by alexander on 05.03.18.
//

#include "CAuthHandler.h"

#include "network.pb.h"
#include "CLog.h"
#include "CUser.h"
#include "CUsersManager.h"

namespace server {

    CClientState CAuthHandler::get_required_state() {
        return CClientState::Unauthorized;
    }

    std::vector<COpCode> CAuthHandler::get_observable_op_codes() {
        return {COpCode::Authorize};
    }

    void CAuthHandler::handle(COpCode opCode, std::shared_ptr<CMessage> message) {
        switch (opCode) {
            case COpCode::Authorize:
                handle_auth(message);
                break;
            default:
                break;
        }
    }

    // Private:

    void CAuthHandler::handle_auth(std::shared_ptr<CMessage> message) {
        auto authMessage = parse<PAuthMessage>(message);

        if (!authMessage) {
            CLog::d("Invalid AuthMessage packet received.");
            return;
        }

        CLog::d("Received AuthMessage: %s / %s",
                authMessage->email().c_str(),
                authMessage->token().c_str());

        CUsersManager::auth(authMessage, [=](std::shared_ptr<CUser> user) {
            if (user) {
                send_auth_succeed(user);
                set_state(CClientState::Authorized);
            } else {
                auto errorMessage = std::make_shared<PErrorMessage>();
                errorMessage->set_code(1); // TODO: Code
                errorMessage->set_message("Something went wrong");
                send(COpCode::AuthError, errorMessage);
            }
        });
    }

    void CAuthHandler::send_auth_succeed(std::shared_ptr<CUser> user) {
        auto message = std::make_shared<PAuthSucceedMessage>();
        message->set_id(user->id);

        send(COpCode::AuthSucceed, message);
    }

}