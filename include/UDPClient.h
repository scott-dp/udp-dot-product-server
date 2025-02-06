//
// Created by scott on 06.02.2025.
//
#include <asio.hpp>
#include "Constants.h"

#ifndef UDPVECTORPRODUCT_UDPCLIENT_H
#define UDPVECTORPRODUCT_UDPCLIENT_H

class UDPClient {
public:
    asio::awaitable<void> start();
};

#endif //UDPVECTORPRODUCT_UDPCLIENT_H
