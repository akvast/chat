//
// Created by alexander on 23.02.18.
//

#pragma once

#include <vector>
#include <cstdint>
#include <google/protobuf/message.h>

namespace common {

    class CMessage {

        uint16_t _opCode;

        std::vector<uint8_t> _data;

    public:

        explicit CMessage(uint16_t opCode, const std::vector<uint8_t> &data);

        explicit CMessage(uint16_t opCode, std::shared_ptr<google::protobuf::Message> message);

        uint16_t get_op_code() const;

        std::vector<uint8_t> get_data() const;

    };

}