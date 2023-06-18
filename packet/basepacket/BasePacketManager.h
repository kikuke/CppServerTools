#ifndef BASE_PACKET_MANAGER
#define BASE_PACKET_MANAGER

#include <sys/types.h>

#include "BasePacketDefine.h"
#include "BasePacketHandler.h"
#include "Logger.h"

class BasePacketManager
{
private:
    BasePacketHandler** handlers;
    size_t handler_size;

    Logger logger;

    //return packetSz
    int HeaderCheck(BASE_PACKET_HEADER& header);

    //if ok return 0 else return error code
    int ExecuteOp(int sock, RingBuffer& buffer, unsigned int mainOp, unsigned int subOp);
    int CatchError(int sock, unsigned int mainOp, unsigned int errorCode);

public:
    BasePacketManager(BasePacketHandler **handlers, size_t handler_size, const char *saveDir, const char *saveFile) : logger(saveDir, saveFile) {
        this->handlers = handlers;
        this->handler_size = handler_size;
    }

    //if error return -1 else return 0
    int execute(int sock, RingBuffer& buffer);
};

#endif