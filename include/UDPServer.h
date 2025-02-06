//
// Created by scott on 06.02.2025.
//
#include <asio.hpp>
#include <iostream>
#include <thread>
#include "Constants.h"

#ifndef UDPVECTORPRODUCT_UDPSERVER_H
#define UDPVECTORPRODUCT_UDPSERVER_H

using namespace std;

class UDPServer {
    asio::ip::udp::socket socket;
public:
    explicit UDPServer(asio::io_context &io_context) : socket(io_context, asio::ip::udp::endpoint(asio::ip::udp::v6(), 3000)) {}
    asio::awaitable<void> handle_request(asio::ip::udp::endpoint endpoint, string message);
    asio::awaitable<void> start();
    int vectorDotProduct(vector<int> vector1, vector<int> vector2);
    int parseVectorsAndCalculateProduct(string message);
};


#endif //UDPVECTORPRODUCT_UDPSERVER_H
