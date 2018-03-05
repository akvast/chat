#include <boost/asio.hpp>

#include <iostream>
#include <thread>

#include "CAppImpl.h"
#include "CConcurrencyImpl.h"
#include "CClient.h"
#include "CClientHandler.h"
#include "../client/database/CDatabase.h"

using namespace client;
using namespace common;

int main() {
    auto ioService = std::make_shared<boost::asio::io_service>();
    auto worker = std::make_shared<boost::asio::io_service::work>(*ioService);

    auto handler = std::make_shared<CClientHandler>();
    auto client = std::make_shared<CClient>(ioService, handler);
    client->connect("127.0.0.1", 8080);

    CAppImpl::instance()->set_concurrency(std::make_shared<CConcurrencyImpl>());

    CDatabase::init();
    CDatabase::open("test.db", "password", [](bool isOpened) {

    });

    std::thread([=]() {
        ioService->run();
    }).detach();

    while (client->get_socket()->is_open()) {
        int32_t cmd;
        std::cout << "Enter cmd: ";
        std::cin >> cmd;

        switch (cmd) {
            case 1: {
                std::string email;
                std::string password;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter password: ";
                std::cin >> password;
                handler->send_authorize(email, password);
                break;
            }
            case 2: {
                std::string email;
                std::string password;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter password: ";
                std::cin >> password;
                handler->send_register(email, password);
                break;
            }
            case 3: {
                std::string query;
                std::cout << "Enter search query: ";
                std::cin >> query;
                handler->send_contacts_search(1, query);
                break;
            }
            default:
                return 0;
        }
    }

    return 0;
}