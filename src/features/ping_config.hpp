
// ping using raw socket


#ifdef		_WIN32

#include <WS2tcpip.h>
#include <WinSock2.h>

#include <stdio.h>

#include <signal.h>

#include <sys/types.h>

#include <setjmp.h>

#include <errno.h>






#elif		defined(LINUX)



#endif		// !_WIN32
