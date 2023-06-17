INCLUDE = -I../file/
MAKE_LOGGER = Logger.o
CC = g++ -g

#Init
init: create_logger


#Operation
create_logger:
	make $(MAKE_LOGGER)

clean:
	rm *.o


#MAKE_LOGGER
Logger.o: Logger.cpp
	$(CC) $(INCLUDE) -c $^