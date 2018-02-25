#include <boost/asio.hpp>
#include <iostream>
#include "CServer.h"
#include "CDatabase.h"

using namespace server;

int main() {

    auto ioService = std::make_shared<boost::asio::io_service>();
    auto worker = std::make_shared<boost::asio::io_service::work>(*ioService);

    CDatabase::init(ioService);
    CDatabase::connect("127.0.0.1", "root", "password", "chat");

    auto server = std::make_shared<CServer>(ioService, 8080);

    ioService->run();
    return 0;
}