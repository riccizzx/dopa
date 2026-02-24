
#pragma once

#ifdef      _WIN32

#include "../../common/config/config.hpp"

#endif

namespace net {

    class TcpSocket {

    public:

        bool startapi();

        bool create();
        
        bool bind(uint16_t port);
        
        bool listen(int backlog = SOMAXCONN);
        
        int accept_client();

        void get_client_info(char* host, char* serv);

        int recv_bytes(void* buf, size_t len);
        int send_bytes(const void* buf, size_t len);

        SOCKET native() const;
       
		int close(SOCKET s);

    private:

        SOCKET sock = INVALID_SOCKET;
        SOCKET client_sock = INVALID_SOCKET;

        WSADATA ws;

        sockaddr_in server_addr;
		sockaddr_in client_addr;
            

    };

}
