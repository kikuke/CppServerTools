INCLUDE =
MAKE_EPOLL = epoll.o
CC = g++ -g

#Init
init: create_epoll


#Operation
create_epoll:
	make $(MAKE_EPOLL)

clean:
	rm *.o


#MAKE_STRUCT
epoll.o: epoll.c
	$(CC) $(INCLUDE) -c $^