OBJECT = posix_multithread.o
TARGET = posix_multithread
LDFLAGS = -lpthread

$(TARGET) : $(OBJECT)
	gcc -o $(TARGET) $(OBJECT) $(LDFLAGS)

$(OBJECT) : posix_multithread.c
	gcc -c posix_multithread.c $(LDFLAGS)

clean:
	rm $(TARGET) $(OBJECT)

