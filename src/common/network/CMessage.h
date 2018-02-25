//
// Created by alexander on 23.02.18.
//

#pragma once

#include <vector>
#include <cstdint>
#include <google/protobuf/message.h>

#include "COpCode.h"

namespace common {

    class CMessage {

        COpCode _opCode;

        std::vector<uint8_t> _data;

    public:

        explicit CMessage(COpCode opCode, const std::vector<uint8_t> &data);

        explicit CMessage(COpCode opCode, std::shared_ptr<google::protobuf::Message> message);

        COpCode get_op_code() const;

        std::vector<uint8_t> get_data() const;

    };

}