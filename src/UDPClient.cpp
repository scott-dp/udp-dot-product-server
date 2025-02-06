//
// Created by scott on 06.02.2025.
//
#include <iostream>

#include "../include/UDPClient.h"

using namespace std;

asio::awaitable<void> UDPClient::start() {
    auto executor = co_await asio::this_coro::executor;
    asio::ip::udp::socket socket(executor, asio::ip::udp::endpoint(asio::ip::udp::v6(), 0));

    // Resolve host (DNS-lookup if needed)
    auto endpoint = (co_await asio::ip::udp::resolver(executor)
            .async_resolve(asio::ip::udp::v6(), "localhost", to_string(3000), asio::use_awaitable))
            .begin()
            ->endpoint();

    std::string message("hello");
    auto bytes_transferred = co_await socket.async_send_to(asio::buffer(message, message.length()), endpoint, asio::use_awaitable);
    cout << "Client: sent: " << message
         << ", to " << endpoint.address() << ":" << endpoint.port() << endl;

    char buffer[max_udp_message_size];
    bytes_transferred = co_await socket.async_receive_from(asio::buffer(buffer, max_udp_message_size), endpoint, asio::use_awaitable);
    cout << "Client: received: " << string(buffer, bytes_transferred)
         << ", from " << endpoint.address() << ":" << endpoint.port() << endl;

}
