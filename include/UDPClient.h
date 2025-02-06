//
// Created by scott on 06.02.2025.
//
#include <asio.hpp>

#ifndef UDPVECTORPRODUCT_UDPCLIENT_H
#define UDPVECTORPRODUCT_UDPCLIENT_H

const size_t max_udp_message_size = 0xffff - 20 - 8;

class UDPClient {
    asio::awaitable<void> start();
};

#endif //UDPVECTORPRODUCT_UDPCLIENT_H
