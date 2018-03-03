#pragma once

#include <boost/asio.hpp>
#include <memory>

namespace common {

    class CMessage;

    class AClientHandler;

    class CClient
            : public std::enable_shared_from_this<CClient> {

        std::shared_ptr<AClientHandler> _handler;

        std::shared_ptr<boost::asio::io_service> _ioService;
        std::shared_ptr<boost::asio::ip::tcp::socket> _socket;

        std::vector<uint8_t> _receivedBuffer;

        std::vector<uint8_t> _encryptKey;
        std::vector<uint8_t> _decryptKey;

    public:

        explicit CClient(std::shared_ptr<boost::asio::io_service> ioService,
                               std::shared_ptr<AClientHandler> handler);

        std::shared_ptr<boost::asio::ip::tcp::socket> get_socket();

        void connect(std::string host, int16_t port);

        void disconnect();

        void start_read();

        void send(std::shared_ptr<CMessage> message);

        void set_encrypt_key(std::vector<uint8_t> encryptKey);

        void set_decrypt_key(std::vector<uint8_t> decryptKey);

    private:

        static void connect_handler(std::shared_ptr<CClient> client, const boost::system::error_code &error);

        static void read_handler(std::shared_ptr<CClient> client, const boost::system::error_code &error, std::size_t bytesTransferred);

        static void send_handler(std::shared_ptr<CClient> client, const boost::system::error_code &error, std::size_t bytesTransferred);

        std::size_t parse_next_message(const uint8_t *data, std::size_t size);

    };

}