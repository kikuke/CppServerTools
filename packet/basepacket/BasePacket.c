#include <string.h>
#include "BasePacket.h"

size_t GetnerateBasePacket(void *packet, const BASE_PACKET_HEADER *header, const void *payload, const BASE_PACKET_TRAILER *trailer) {
    unsigned char *packetAddr = (unsigned char *)packet;
    size_t packetLen = 0;

    memcpy(packetAddr, header, sizeof(*header));
    packetAddr += sizeof(*header);
    packetLen += sizeof(*header);

    if (payload != NULL) {
        memcpy(packetAddr, payload, header->payloadLen);
        packetAddr += header->payloadLen;
        packetLen += header->payloadLen;
    }

    memcpy(packetAddr, trailer, sizeof(*trailer));
    packetLen += sizeof(*trailer);

    return packetLen;
}