
#include "wscan.h"

int main()
{
    printf("welcome to wscan server!\n");
    printf("guide options below\n\n");

    net::server sv;

    try {
        sv.init();   // init winsock

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;

    }

    usage();

    char choice = 0;

    while (true) {

        printf("\n> ");
        if (scanf(" %c", &choice) != 1) {
            continue;
        }

        switch (choice) {

        case 'h':
            printf("setting up server...\n");
            printf("this server works on a socket model in your pc,\n");
            printf("binding your ip and a default port\n");
            printf("start local server? (Y/N)\n");

            char start;
            scanf(" %c", &start);

            if (start == 'Y' || start == 'y') {
                sv.setupsock(); // setup server socket and address



            }

            break;

        case 'q':
            printf("shutting down server...\n");
            return 0;


        default:
            printf("unknown option\n");
            break;

        }

    }

}
