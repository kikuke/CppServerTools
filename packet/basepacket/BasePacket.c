#include <string.h>
#include "BasePacket.h"

void *GetnerateBasePacket(void *packet, const BASE_PACKET_HEADER *header, const void *payload, const BASE_PACKET_TRAILER *trailer) {
    unsigned char *packetAddr = (unsigned char *)packet;

    memcpy(packetAddr, header, sizeof(*header));
    packetAddr += sizeof(*header);

    memcpy(packetAddr, payload, header->payloadLen);
    packetAddr += header->payloadLen;

    memcpy(packetAddr, trailer, sizeof(*trailer));

    return packet;
}