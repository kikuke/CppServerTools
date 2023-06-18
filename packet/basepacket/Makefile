INCLUDE = -I../../struct
MAKE_BASE_PACKET = BasePacket.o BasePacketManager.o
CC = g++ -g

#Init
init: create_base_packet


#Operation
create_base_packet:
	make $(MAKE_BASE_PACKET)

clean:
	rm *.o


#MAKE_BASE_PACKET
BasePacket.o: BasePacket.c
	$(CC) $(INCLUDE) -c $^

BasePacketManager.o: BasePacketManager.cpp
	$(CC) $(INCLUDE) -c $^