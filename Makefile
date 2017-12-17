#Making

OBJECT = posix_multithread.o
TARGET = posix_multithread

$(OBJECT) : posix_multithread.c
    gcc -c posix_multithread.c -lpthread

$(TARGET) : $(OBJECT)
    gcc -o $(TARGET) $(OBJECT)

clean:
rm -f $(TARGET)

