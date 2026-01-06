
#include "tcmp.h"
static u_short calculate_checksum(u_int16_t *addr, int len)
{
    u_int32_t sum = 0;

    for (int i = 0; i < len / 2; i++)
    {
        sum += *addr++;
    }

    if (len % 2 == 1)
        sum += ((u_int8_t *)addr)[len - 1] << 8;

    while (sum >> 16)
    {
        sum = (sum & 0xFFFF) + (sum >> 16);
    }

    return ~sum;
}