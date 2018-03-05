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
        return {
                COpCode::Authorize,
                COpCode::Register
        };
    }

    void CAuthHandler::handle(COpCode opCode, std::shared_ptr<CMessage> message) {
        switch (opCode) {
            case COpCode::Authorize:
                handle_auth(message);
                break;
            case COpCode::Register:
                handle_register(message);
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
                authMessage->password().c_str());

        CUsersManager::with_email(authMessage->email(), [=](std::shared_ptr<CUser> user) {
            if (user && user->password == authMessage->password()) {
                send_auth_succeed(user->name);
                set_state(CClientState::Authorized);
            } else {
                auto errorMessage = std::make_shared<PErrorMessage>();
                errorMessage->set_code(1); // TODO: Code
                errorMessage->set_message("Invalid email or password");
                send(COpCode::AuthError, errorMessage);
            }
        });
    }

    void CAuthHandler::send_auth_succeed(std::string name) {
        auto message = std::make_shared<PAuthSucceedMessage>();
        message->set_name(name);

        send(COpCode::AuthSucceed, message);
    }

    void CAuthHandler::handle_register(std::shared_ptr<CMessage> message) {
        auto registerMessage = parse<PRegisterMessage>(message);

        if (!registerMessage) {
            CLog::d("Invalid RegisterMessage packet received.");
            return;
        }

        CLog::d("Received RegisterMessage: %s / %s",
                registerMessage->email().c_str(),
                registerMessage->password().c_str());

        // TODO: Implement registration

        auto error = std::make_shared<PErrorMessage>();
        error->set_code(1);
        error->set_message("Not yet implemented.");

        send(COpCode::RegisterError, error);
    }

}