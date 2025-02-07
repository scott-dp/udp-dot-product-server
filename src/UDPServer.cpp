//
// Created by scott on 06.02.2025.
//

#include "../include/UDPServer.h"
using namespace std;

asio::awaitable<void> UDPServer::handle_request(asio::ip::udp::endpoint endpoint, string message) {
    try {
        message = to_string(parseVectorsAndCalculateProduct(message));
    } catch(const exception& e) {
        message = "Vectors in incorrect format";
    }
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

int UDPServer::vectorDotProduct(vector<int> vector1, vector<int> vector2) {
    int result = 0;
    for (int i = 0; i < vector1.size(); ++i) {
        result+=vector1[i]*vector2[i];
    }
    return result;
}

int UDPServer::parseVectorsAndCalculateProduct(string message) {
    vector<int> vector1;
    vector<int> vector2;
    int currentVector = 1;
    for (int messageIndex = 0; messageIndex < message.size(); ++messageIndex) {
        if (message[messageIndex] == '\n') {
            currentVector++;
            continue;
        } else if (message[messageIndex] == ',') {
            continue;
        } else {
            string number;
            while (message[messageIndex] != ',' && message[messageIndex] != '\n' && messageIndex < message.size()) {
                //message[messageCharacter] should be a number here
                number+=message[messageIndex];
                messageIndex++;
            }
            messageIndex--;
            if (currentVector == 1) {
                cout << "vector 1" << number <<endl;
                vector1.push_back(stoi(number));
            } else {
                cout << "vector 1" << number <<endl;
                vector2.push_back(stoi(number));
            }
        }
    }
    return vectorDotProduct(vector1, vector2);
}