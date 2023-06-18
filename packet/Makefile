MAKE_PACKET =
SUBDIRS = basepacket
CC = g++ -g

#Init
init: create_packet


#Operation
create_packet:
	for DIR in $(SUBDIRS); do \
		$(MAKE) -C $$DIR; \
	done

clean: 
	for DIR in $(SUBDIRS); do \
		$(MAKE) -C $$DIR clean; \
	done
	rm *.o