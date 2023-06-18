INCLUDE =
MAKE_BASE_PACKET = BasePacket.o
CC = g++ -g

#Init
init: create_base_packet


#Operation
create_base_packet:
	make $(MAKE_BASE_PACKET)

clean:
	rm *.o


#MAKE_STRUCT
BasePacket.o: BasePacket.c
	$(CC) $(INCLUDE) -c $^