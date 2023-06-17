MAKE_FILE = file.o
CC = g++ -g

#Init
init: create_file


#Operation
create_file:
	make $(MAKE_FILE)

clean:
	rm *.o


#MAKE_FILE
file.o: file.c
	$(CC) -c $^