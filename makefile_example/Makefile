TARGET = app
SOURCES = com_main.o compar.o

app: $(SOURCES)
	gcc -o $(TARGET) $(SOURCES)

com_main.o: com_main.c
	gcc -c com_main.c

compar.o: compar.c
	gcc -c compar.c

clean:
	rm $(TARGET) $(SOURCES)
