#pragma once

namespace common {

    enum class COpCode : uint16_t {

        HandshakeInit = 1,
        HandshakePublicKey,
        HandshakeClientKey,
        HandshakeServerKey,

        Authorize = 10,
        AuthSucceed,
        AuthError,

        Register = 20,
        RegisterSucceed,
        RegisterError,
    };

}