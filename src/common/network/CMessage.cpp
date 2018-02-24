//
// Created by alexander on 23.02.18.
//

#include "CMessage.h"

namespace common {

    CMessage::CMessage(uint16_t opCode, const std::vector<uint8_t> &data)
            : _opCode(opCode),
              _data(data) {

    }

    CMessage::CMessage(uint16_t opCode, std::shared_ptr<google::protobuf::Message> message)
            : _opCode(opCode) {

        auto size = message->ByteSize();
        _data.resize(size);
        message->SerializeToArray(_data.data(), size);
    }

    uint16_t CMessage::get_op_code() const {
        return _opCode;
    }

    std::vector<uint8_t> CMessage::get_data() const {
        return _data;
    }

}