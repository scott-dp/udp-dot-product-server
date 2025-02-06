cmake_minimum_required(VERSION 3.28)
project(udpVectorProduct)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add WIN32 version macro
add_compile_definitions(_WIN32_WINNT=0x0A00)

add_executable(udpVectorProduct
        main.cpp
        include/UDPServer.h
        src/UDPServer.cpp
        include/UDPClient.h
        src/UDPClient.cpp
        include/Constants.h
)

# Link required libraries
target_link_libraries(udpVectorProduct PRIVATE ws2_32 mswsock)
