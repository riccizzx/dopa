
#include "servercfg.hpp"

bool net::server::start() {


    if (!listener.startapi()) {
        handle_error("WSAStartup failed");
        return false;
    }


    if (!listener.create()) {
        handle_error("socket creation failed");
        return false;
    }


    if (!listener.bind(DEFAULT_PORT)) {
        handle_error("bind failed");
        return false;
    }


    if (!listener.listen(SOMAXCONN)) {
        handle_error("listen failed");
        return false;
    }

    std::cout << "\nserver is listening for incomming connections...\n";
    std::cout << "waiting for clients to connect...\n\n";

	SOCKET client_sock = listener.accept_client();

    if (client_sock != INVALID_SOCKET) {

        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];


        listener.get_client_info(host, serv);

        std::cout << "client connected: \n";

    }

	// client and server communication logic here

	while (true) {

		char buffer[1024];

		memset(buffer, 0, sizeof(buffer));

		int bytes_recv = listener.recv_bytes(buffer, sizeof(buffer));
		if (bytes_recv > 0)
        {
			std::string recv_msg(buffer, bytes_recv);
			std::cout << "Client: " << recv_msg << std::endl;
		
            if (recv_msg == "exit") {
				std::cout << "Client requested to quit!" << std::endl;
				break;

			// send client a response message
            }

			listener.send_bytes(buffer, bytes_recv);
			// to send custom message from server to client uncomment below
			//std::string msg;
			//std::getline(std::cin, msg);
			//listener.send_bytes(msg.c_str(), msg.size());
		}

        else if (bytes_recv == 0) {
			std::cout << "Client disconnected gracefully.\n";
        
        }

		closesocket(client_sock);
		std::cout << "Client disconnected.\n";

	}

    return true;

}

