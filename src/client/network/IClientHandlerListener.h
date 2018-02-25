//
// Created by alexander on 25.02.18.
//

#pragma once

namespace client {

    class IClientHandlerListener {

    public:

        virtual void on_connected() = 0;

        virtual void on_handshake_complete() = 0;

        virtual void on_authorized() = 0;

        virtual void on_auth_failed() = 0;

        virtual void on_disconnected() = 0;

    };

}