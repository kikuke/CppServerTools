#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "socket.h"
#include "BasePacket.h"
#include "RingBuffer.h"
#include "Logger.h"
#include "BasePacketManager.h"

#define SERV_ADDR INADDR_ANY
#define SERV_PORT 1234
#define EPOLL_SIZE 5000

using namespace std;

int main(void)
{
    int serv_sock = -1;
    //Todo: GenerateBasePacket Test
    char buf[1024];
    const char* msg = "HELLO WORLD";
    BasePacketHeader header = {
        TCP_PACKET_START_CODE,
        (unsigned int)strlen(msg)
    };
    BASE_PACKET_TRAILER trailer = {
        TCP_PACKET_END_CODE
    };
    BasePacketManager packetManager(NULL, 0, "", "");

    GetnerateBasePacket(buf, &header, msg, &trailer);

    exit(0);
}