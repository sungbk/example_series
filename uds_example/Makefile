OBJECT = uds_example.o
TARGET = uds_example

$(TARGET) : $(OBJECT)
	g++ -o $(TARGET) $(OBJECT)

$(OBJECT) : uds_example.cpp
	g++ -c uds_example.cpp

clean :
	rm $(TARGET) $(OBJECT)
