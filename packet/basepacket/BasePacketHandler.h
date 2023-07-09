#ifndef BASE_PACKET_HANDLER
#define BASE_PACKET_HANDLER

#include "BasePacket.h"
#include "RingBuffer.h"

class BasePacketHandler
{
private:
    const unsigned int mainOp;

    //if ok return 0 else -1
    int CheckTrailer(BASE_PACKET_TRAILER& trailer) {
        if (trailer.endCode != TCP_PACKET_END_CODE)
            return -1;
        
        return 0;
    }

protected:
    //abstract data, return data
    //  if failed return NULL
    template <typename T>
    int UnpackData(RingBuffer& buffer, T* data) {
        BASE_PACKET_TRAILER trailer;

        if(data != NULL) {
            buffer >> *data;
        }
        buffer >> trailer;

        if (CheckTrailer(trailer) < 0)
            return -1;

        return 0;
    }

public:
    BasePacketHandler(unsigned int _mainOp) : mainOp(_mainOp) {};
    
    unsigned int getMainOp() {
        return mainOp;
    }

    //success return 0 else return error code
    virtual int execute(int sock, unsigned int subOp, RingBuffer& buffer) = 0;
    //success return 0 else return error code
    virtual int catchError(int sock, unsigned int errorCode) = 0;
};

#endif