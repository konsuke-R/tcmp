#include "tcmp.h"

int create_socket()
{
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock < 0)
    {
        perro("socket creation failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}