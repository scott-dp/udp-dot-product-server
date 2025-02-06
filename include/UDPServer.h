//
// Created by scott on 06.02.2025.
//
#include <asio.hpp>
#include <iostream>
#include <thread>

#ifndef UDPVECTORPRODUCT_UDPSERVER_H
#define UDPVECTORPRODUCT_UDPSERVER_H

using namespace std;

const size_t max_udp_message_size = 0xffff - 20 - 8;

class UDPServer {
    asio::ip::udp::socket socket;
public:
    explicit UDPServer(asio::io_context &io_context) : socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v6(), 3000)) {}
    asio::awaitable<void> handle_request(asio::ip::udp::endpoint endpoint, string message);
    asio::awaitable<void> start();

};


#endif //UDPVECTORPRODUCT_UDPSERVER_H
