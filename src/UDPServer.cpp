//
// Created by scott on 06.02.2025.
//

#include "../include/UDPServer.h"

asio::awaitable<void> UDPServer::handle_request(asio::ip::udp::endpoint endpoint, string message) {
    co_await socket.async_send_to(asio::buffer(message, message.length()), endpoint, asio::use_awaitable);
    cout << "Server: sent: " << message
         << ", to " << endpoint.address() << ":" << endpoint.port() << endl;
}

asio::awaitable<void> UDPServer::start() {
    for (;;) {
        char buffer[max_udp_message_size];
        asio::ip::udp::endpoint endpoint;
        auto bytes_transferred = co_await socket.async_receive_from(asio::buffer(buffer, max_udp_message_size), endpoint, asio::use_awaitable);

        auto message = string(buffer, bytes_transferred);
        cout << "Server: received: " << message
             << ", from " << endpoint.address() << ":" << endpoint.port() << endl;

        co_spawn(socket.get_executor(), handle_request(std::move(endpoint), std::move(message)), asio::detached);
    }
}

double UDPServer::vectorProduct(vector<double> vector1, vector<double> vector2) {
    double result = 0;
    for (int i = 0; i < vector1.size(); ++i) {
        result+=vector1[i]*vector2[i];
    }
    return result;
}
