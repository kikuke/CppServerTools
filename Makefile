INCLUDE = -Isocket/ -Istruct/ -Ilog/
SUBDIRS = file socket struct log
MODULE = file/file.o socket/socket.o struct/RingBuffer.o log/Logger.o
RESULT = main
CC = g++ -g


#Init
init: create_main


#Operation
create_main:
	for DIR in $(SUBDIRS); do \
		$(MAKE) -C $$DIR; \
	done
	make $(RESULT)

clean: 
	for DIR in $(SUBDIRS); do \
		$(MAKE) -C $$DIR clean; \
	done
	rm *.o
	rm $(RESULT)


#Main File
main: main.o $(MODULE)
	$(CC) -o $@ $^


#Application
main.o: main.cpp
	$(CC) $(INCLUDE) -c $^