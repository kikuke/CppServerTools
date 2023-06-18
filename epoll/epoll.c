#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/epoll.h>

#include "epoll.h"

int SetNonblockFd(int fd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    return fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

int InitEpoll(struct epoll_event** ep_events, size_t epoll_sz)
{
    int epfd;

    epfd = epoll_create(epoll_sz);
    *ep_events = (struct epoll_event*)malloc(sizeof(struct epoll_event) * epoll_sz);

    return epfd;
}

int SetETServSock(int epfd, int serv_sock)
{
    struct epoll_event event;

    if (SetNonblockFd(serv_sock) < 0)
        return -1;
    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    return epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);
}

int AddETClntSock(int epfd, int clnt_sock)
{
    struct epoll_event event;
    
    if (SetNonblockFd(clnt_sock) < 0)
        return -1;
    event.events = EPOLLIN|EPOLLET;
    event.data.fd = clnt_sock;
    return epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
}

ssize_t ReadET(int fd, void* buf, size_t sz, ssize_t (*etReadFunc)(int, const void*, size_t))
{
    ssize_t str_len = 0;
    ssize_t temp_len;

    while(1) {
        temp_len = read(fd, buf,  sz);
        if(temp_len == 0){
            return 0;
        }
        else if(temp_len < 0)
        {
            if(errno == EAGAIN)
                return str_len;
        }
        else
        {
            str_len += etReadFunc(fd, buf, temp_len);
        }
    }
}
