SUBDIRS = file socket packet epoll struct log
MODULE = file/file.o socket/socket.o packet/basepacket/BasePacket.o epoll/epoll.o struct/RingBuffer.o log/Logger.o packet/basepacket/BasePacketManager.o
RESULT = kikuke_server_tools.a


#Init
init: create_archive


#Operation
create_archive:
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
$(RESULT): $(MODULE)
	ar ru $@ $^
	ranlib $@