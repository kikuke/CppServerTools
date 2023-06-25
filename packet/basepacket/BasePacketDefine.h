#ifndef BASE_PACKET_DEFINE_H
#define BASE_PACKET_DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif

#define TCP_PACKET_START_CODE 0x77
#define TCP_PACKET_END_CODE 0x33

typedef struct BasePacketHeader {
    unsigned int startCode;
    unsigned int payloadLen;

    unsigned int mainOp;
    unsigned int subOp;

    unsigned int flag;
    unsigned int auth;
} BASE_PACKET_HEADER;

typedef struct BasePacketTrailer {
    unsigned int endCode;
} BASE_PACKET_TRAILER;

#ifdef __cplusplus
}
#endif

#endif