
//		ALL HEADERS INCLUDE FOR MAIN

#pragma once


#ifndef		GLOBAL_WSCAN_H


#define		GLOBAL_WSCAN_H


#include "../src/features/ping_config.hpp"
#include "../src/server/servercfg.hpp"

void usage()
{

	std::cout << "options:\n";
	std::cout << "  -h host           start host ip address to send ping requests to\n";
	std::cout << "  -q quit			  to quit program\n";

	printf("\n");
}

#endif		// GLOBAL_WSCNAN_H