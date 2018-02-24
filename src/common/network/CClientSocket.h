#pragma once

#include <boost/asio.hpp>
#include <memory>

namespace common {

    class CMessage;

    class CSocketHandler;

    class CClientSocket
            : public std::enable_shared_from_this<CClientSocket> {

        std::shared_ptr<CSocketHandler> _handler;

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::ip::tcp::socket> _socket;

        std::vector<uint8_t> _receivedBuffer;

        std::vector<uint8_t> _encryptKey;
        std::vector<uint8_t> _decryptKey;

    public:

        explicit CClientSocket(std::shared_ptr<boost::asio::io_service> ioService,
                               std::shared_ptr<CSocketHandler> handler);

        std::shared_ptr<boost::asio::ip::tcp::socket> get_socket() const;

        void connect(std::string host, int16_t port);

        void start_read();

        void send(std::shared_ptr<CMessage> message);

        void set_encrypt_key(std::vector<uint8_t> encryptKey);

        void set_decrypt_key(std::vector<uint8_t> decryptKey);

    protected:

        void connect_handler(const boost::system::error_code &error);

        void read_handler(const boost::system::error_code &error, std::size_t bytesTransferred);

        void send_handler(const boost::system::error_code &error, std::size_t bytesTransferred);

        std::size_t parse_next_message(const uint8_t *data, std::size_t size);

    };

}