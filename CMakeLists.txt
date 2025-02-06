cmake_minimum_required(VERSION 3.28)
project(udpVectorProduct)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(udpVectorProduct main.cpp
        include/UDPServer.h
        src/UDPServer.cpp
        include/UDPClient.h
        src/UDPClient.cpp
)

target_link_libraries(udpVectorProduct PRIVATE ws2_32)
