#include <sys/types.h>

// RFC792より、ICMP Echo Requesrt/Replyヘッダの定義
struct icmpechoheader
{
    u_int8_t type;
    u_int8_t code;
    u_int16_t checksum;
    u_int16_t id;
    u_int16_t sequence;
};

// Chekcksum処理
u_int16_t checksum(u_int16_t *buf, int size)
{
    u_int32_t sum = 0;

    while (size > 1)
    {
        sum += *buf++;
        size -= 2;
    }

    if (size == 1)
    {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return ~sum;
};
