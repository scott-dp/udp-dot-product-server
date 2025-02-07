![image](https://github.com/user-attachments/assets/1d12f99d-50d7-40df-9935-65a69087824c)
<h2>Compile on windows:</h2>
g++ -std=c++20 -D_WIN32_WINNT=0x0A00 main.cpp src/UDPClient.cpp src/UDPServer.cpp -o udpVectorProduct -lws2_32 -lmswsock
