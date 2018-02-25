#pragma once

namespace client {

    enum class CConnectionState {

        Disconnected,
        Connecting,
        Connected,
        Unauthorized,
    };

}