INCLUDE =
MAKE_SOCKET = socket.o
CC = g++ -g

#Init
init: create_socket


#Operation
create_socket:
	make $(MAKE_SOCKET)

clean:
	rm *.o


#MAKE_STRUCT
socket.o: socket.c
	$(CC) $(INCLUDE) -c $^