OBJECT = posix_multithread.o
TARGET = posix_multithread

$(TARGET) : $(OBJECT)
	gcc -o $(TARGET) $(OBJECT) -lpthread

$(OBJECT) : posix_multithread.c
	gcc -c posix_multithread.c -lpthread

clean:
	rm $(TARGET) $(OBJECT)

