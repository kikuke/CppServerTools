#include "BasePacketManager.h"

int BasePacketManager::ExecuteOp(int sock, RingBuffer& buffer, unsigned int mainOp, unsigned int subOp)
{
    for(int i=0; i<handler_size; i++){
        if((*(handlers[i])).getMainOp() == mainOp)
            return (*(handlers[i])).execute(sock, subOp, buffer);
    }

    logger.Log(LOGLEVEL::ERROR, "ExecuteOp() - Undefined MainOp: %d", mainOp);
    return 0;
}

int BasePacketManager::CatchError(int sock, unsigned int mainOp, unsigned int errorCode)
{
    for(int i=0; i<handler_size; i++){
        if((*(handlers[i])).getMainOp() == mainOp)
            return (*(handlers[i])).catchError(sock, errorCode);
    }

    logger.Log(LOGLEVEL::ERROR, "CatchError() - Undefined MainOp: %d", mainOp);
    return -1;
}

int BasePacketManager::execute(int sock, RingBuffer& buffer)
{
    BASE_PACKET_HEADER header;
    int packet_size;
    int errorCode;
    
    size_t useSz = buffer.getUseSize();

    if((sizeof(BASE_PACKET_HEADER) + sizeof(BASE_PACKET_TRAILER)) > useSz)
        return 0;

    buffer.peek(&header, sizeof(BASE_PACKET_HEADER));

    if ((packet_size = HeaderCheck(header)) < 0) {
        logger.Log(LOGLEVEL::ERROR, "Packet Brokened at socket: %d", sock);
        buffer.flush();
        //Todo: -1 or 0
        return -1;
    }
    //packet size check
    if(useSz < packet_size){
        logger.Log(LOGLEVEL::DEBUG, "Not Full Size Packet");
        return 0;
    }
    buffer >> header;

    if ((errorCode = ExecuteOp(sock, buffer, header.mainOp, header.subOp)) != 0) {
        logger.Log(LOGLEVEL::ERROR, "ExecuteOP() - MainOp: %d, SubOp: %d", header.mainOp, header.subOp);
        CatchError(sock, header.mainOp, errorCode);
        //Todo: -1 or 0
        return -1;
    }

    return 0;
}

int BasePacketManager::HeaderCheck(BASE_PACKET_HEADER& header)
{
    //인증, 인가, 플래그 체크 등등의 작업하기
    if(!(header.startCode == TCP_PACKET_START_CODE)){
        logger.Log(LOGLEVEL::ERROR, "TCPHeaderCheck() - Undefined StartCode");
        return -1;
    }

    return sizeof(BASE_PACKET_HEADER) + header.payloadLen + sizeof(BASE_PACKET_TRAILER);
}