
//		ALL HEADERS INCLUDE FOR MAIN

#pragma once


#ifndef		GLOBAL_WSCAN_H


#define		GLOBAL_WSCAN_H

#include "../src/common/config/config.hpp"
#include "../src/server/servercfg.hpp"
#include "../src/common/net/socket.hpp"
#include "../src/common/protocol/message.hpp"

void usage()
{

	std::cout << "options:\n";
	std::cout << "  -h host	start host ip address to send ping requests to\n";
	std::cout << "  -q quit	to quit program\n";

}

#endif		// GLOBAL_WSCNAN_H