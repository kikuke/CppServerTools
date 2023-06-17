INCLUDE =
MAKE_STRUCT = RingBuffer.o
CC = g++ -g

#Init
init: create_struct


#Operation
create_struct:
	make $(MAKE_STRUCT)

clean:
	rm *.o


#MAKE_STRUCT
RingBuffer.o: RingBuffer.cpp
	$(CC) $(INCLUDE) -c $^