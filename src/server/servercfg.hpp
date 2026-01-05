//  

#ifdef      _WIN32

#ifndef		SOCKET_SERVER_HPP
#define		SOCKET_SERVER_HPP

//#include "server_log.hpp"

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>


#pragma comment(lib, "ws2_32.lib")

#endif

constexpr int PORT = 9909;

namespace net {

    // server error handler
    inline void handle_error(const char* msg)
    {

        int err = WSAGetLastError();
        fprintf(stderr, "[!] %s: WSA error %d\n", msg, err);

        WSACleanup();
        exit(EXIT_FAILURE);

    }


    class server {

    public:

        bool init();

        void setupsock();

        void con_infos(char* host, char* service);

        void handle_connections();
        void normal_channel();

        void multiplex();


    private:

        WSADATA ws;

        SOCKET server_sock, client_sock;

        sockaddr_in server_addr, client_addr;

        int serverlen = sizeof(server_addr);

        char buffer = 1024;

    };

}

#endif  	// !SOCKET_SERVER_HPP

