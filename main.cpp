#include <stdlib.h>
#include <iostream>

#include "socket.h"
#include "RingBuffer.h"
#include "Logger.h"

#define SERV_ADDR INADDR_ANY
#define SERV_PORT 1234
#define EPOLL_SIZE 5000

using namespace std;

int main(void)
{
    int serv_sock = -1;
    //Logger::LoggerSetting(LOGLEVEL::DEBUG);
    //Logger log("../", "test");
    if ((serv_sock = SetTCPServSock(SERV_ADDR, SERV_PORT, SOMAXCONN, true)) < 0) {
        perror("SetTCPServSock");
    }

    exit(0);
}