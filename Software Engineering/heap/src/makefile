CC = g++
_OBJECTS = heap.o create.o insert.o delete.o display.o
OBJECTS = $(patsubst %, asd, hello helo) 

heap: $(OBJECTS)
	echo $(OBJECTS); $(CC) $(OBJECTS) -o heap

src/%.o: src/$@.c src/functions.h
	$(CC) -c $*.cpp

clean:
	-rm *.o
