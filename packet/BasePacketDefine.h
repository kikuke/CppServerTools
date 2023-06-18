#ifndef BASE_PACKET_DEFINE_H
#define BASE_PACKET_DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif

#define TCP_PACKET_START_CODE 0x77
#define TCP_PACKET_END_CODE 0x33

typedef struct BasePacketHeader {
    unsigned int startCode : 8;
    unsigned int payloadLen : 16; // 3Byte

    unsigned int mainOp : 4;
    unsigned int : 4;
    unsigned int subOp : 8; // 2Byte

    unsigned int flag : 12;
    unsigned int auth : 12; // 3Byte
} BASE_PACKET_HEADER; // 8Byte

typedef struct BasePacketTrailer {
    unsigned int endCode : 8;
    unsigned int : 24;
} BASE_PACKET_TRAILER;

#ifdef __cplusplus
}
#endif

#endif