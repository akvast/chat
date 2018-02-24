#include <boost/asio.hpp>

#include <iostream>
#include <thread>

#include "CClientSocket.h"
#include "CClientSocketHandler.h"

using namespace client;
using namespace common;

int main() {
    auto ioService = std::make_shared<boost::asio::io_service>();
    auto worker = std::make_shared<boost::asio::io_service::work>(*ioService);

    auto handler = std::make_shared<CClientSocketHandler>();
    auto client = std::make_shared<CClientSocket>(ioService, handler);
    client->connect("127.0.0.1", 8866);

    std::thread([=]() {
        ioService->run();
    }).detach();

    while (client->get_socket()->is_open()) {
        int32_t cmd;
        std::cout << "Enter cmd: ";
        std::cin >> cmd;

        switch (cmd) {
            case 1: {
                std::string login;
                std::string password;
                std::cout << "Enter login: ";
                std::cin >> login;
                std::cout << "Enter password: ";
                std::cin >> password;
                handler->send_auth(client, login, password);
                break;
            }
            default:
                return 0;
        }
    }

    return 0;
}