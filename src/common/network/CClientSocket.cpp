//
// Created by alexander on 23.02.18.
//

#include "CClientSocket.h"

#include <boost/bind.hpp>

#include "CLog.h"
#include "CMessage.h"
#include "CSocketHandler.h"
#include "aes256.h"

namespace common {

    CClientSocket::CClientSocket(std::shared_ptr<boost::asio::io_service> ioService,
                                 std::shared_ptr<CSocketHandler> handler)
            : _ioService(std::move(ioService)),
              _handler(std::move(handler)) {

        _socket = std::make_shared<boost::asio::ip::tcp::socket>(*_ioService);
        _receivedBuffer.resize(2048);
    }

    std::shared_ptr<boost::asio::ip::tcp::socket> CClientSocket::get_socket() const {
        return _socket;
    }

    void CClientSocket::connect(std::string host, int16_t port) {
        // TODO: Host resolver

        auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(host),
                                                       static_cast<unsigned short>(port));

        _socket->async_connect(endpoint,
                               boost::bind(&CClientSocket::connect_handler, this,
                                           boost::asio::placeholders::error));
    }

    void CClientSocket::start_read() {
        _socket->async_receive(boost::asio::buffer(_receivedBuffer.data(), _receivedBuffer.size()),
                               boost::bind(&CClientSocket::read_handler, this,
                                           boost::asio::placeholders::error,
                                           boost::asio::placeholders::bytes_transferred));
    }

    void CClientSocket::send(std::shared_ptr<CMessage> message) {
        auto data = message->get_data();
        std::vector<uint8_t> sendBuffer;
        sendBuffer.resize(4 + data.size());

        // Header: Packet Size & Op Code
        *(uint16_t *) sendBuffer.data() = static_cast<uint16_t>(data.size());
        *(uint16_t *) (sendBuffer.data() + 2) = static_cast<uint16_t>(message->get_op_code());
        // Body:

        if (!_encryptKey.empty()) {
            auto encrypted = aes_cbc_encrypt(data.data(), data.size(), _encryptKey.data());
            sendBuffer.resize(4 + encrypted.second);
            *(uint16_t *) sendBuffer.data() = static_cast<uint16_t>(encrypted.second);
            memcpy(sendBuffer.data() + 4, encrypted.first, encrypted.second);
            free(encrypted.first);
        } else {
            memcpy(sendBuffer.data() + 4, data.data(), data.size());
        }

        _socket->async_send(boost::asio::buffer(sendBuffer.data(), sendBuffer.size()),
                            boost::bind(&CClientSocket::send_handler, this,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
    }

    void CClientSocket::set_encrypt_key(std::vector<uint8_t> encryptKey) {
        _encryptKey = std::move(encryptKey);
    }

    void CClientSocket::set_decrypt_key(std::vector<uint8_t> decryptKey) {
        _decryptKey = std::move(decryptKey);
    }

    // Private:

    void CClientSocket::connect_handler(const boost::system::error_code &error) {
        CLog::d("Connected...");
        if (_handler)
            _handler->on_connected(shared_from_this());

        start_read();
    }

    void CClientSocket::read_handler(const boost::system::error_code &error, std::size_t bytesTransferred) {
        CLog::d("Received " + std::to_string(bytesTransferred) + " bytes.");

        if (bytesTransferred > 0) {
            uint8_t *pointer = _receivedBuffer.data();
            std::size_t messageSize = 0;
            do {
                messageSize = parse_next_message(pointer, bytesTransferred);
                bytesTransferred -= messageSize;
                pointer += messageSize;
            } while (messageSize > 0 && bytesTransferred > 2);
        } else {
            CLog::d("Connection closed.");
            _socket->close();
            return;
        }

        if (bytesTransferred > 0) {
            CLog::d("Bad packet.");
            _socket->close();
            return;
        }

        // Read next packet:
        start_read();
    }

    void CClientSocket::send_handler(const boost::system::error_code &error, std::size_t bytesTransferred) {
        CLog::d("Sent " + std::to_string(bytesTransferred) + " bytes.");
    }

    std::size_t CClientSocket::parse_next_message(const uint8_t *data, std::size_t size) {
        uint16_t messageSize = *data;
        if (messageSize + 4 > size) {
            return 0;
        }
        auto opCode = static_cast<COpCode>(*((uint16_t *) (data + 2)));
        std::vector<uint8_t> messageData(data + 4, data + 4 + messageSize);

        if (!_decryptKey.empty()) {
            auto decrypted = aes_cbc_decrypt(messageData.data(), messageData.size(), _decryptKey.data());
            auto pointer = static_cast<uint8_t *>(decrypted.first);
            messageData = std::vector<uint8_t>(pointer, pointer + decrypted.second);
            free(decrypted.first);
        }

        auto message = std::make_shared<CMessage>(opCode, messageData);
        if (_handler)
            _handler->on_message(shared_from_this(), message);

        return messageSize + 4;
    }

}