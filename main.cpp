#include <iostream>
#include <asio.hpp>

#include "include/UDPClient.h"
#include "include/UDPServer.h"


int main() {
    asio::io_context event_loop(1);

    UDPServer echo_server(event_loop);
    co_spawn(event_loop, echo_server.start(), asio::detached);

    UDPClient echo_client;
    co_spawn(event_loop, echo_client.start(), asio::detached);

    event_loop.run();
}
