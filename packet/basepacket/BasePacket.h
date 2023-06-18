#ifndef BASE_PACKET_H
#define BASE_PACKET_H

#ifdef __cplusplus
extern "C" {
#endif

#include "BasePacketDefine.h"

//return packet addr
void *GetnerateBasePacket(void *packet, const BASE_PACKET_HEADER *header, const void *payload, const BASE_PACKET_TRAILER *trailer);

#ifdef __cplusplus
}
#endif

#endif