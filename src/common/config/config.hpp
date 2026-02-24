
#ifndef			COMMON_CONFIG_CONFIG_HPP


#define			COMMON_CONFIG_CONFIG_HPP


#ifdef			_WIN32


//library includes
#include <WS2tcpip.h>
#include <winsock2.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#pragma comment(lib, "ws2_32.lib")


#else
#define __linux__
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


#endif 		// _WIN32


#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>
#include <cstdint>


namespace config { // default configuration values

	constexpr int DEFAULT_PORT = 8080; // default port number to host the server 

	const std::string DEFAULT_HOST = "192.168.0.1"; // default host ip address

}


inline void handle_error(const char* msg) {
	
	int err = WSAGetLastError();
	fprintf(stderr, "[!] % s: server error % d\n", msg, err);

	WSACleanup();
	exit(EXIT_FAILURE);

}


#endif		// COMMON_CONFIG_CONFIG_HPP