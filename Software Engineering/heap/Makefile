CC = g++
OBJECTS = heap.o create.o insert.o delete.o display.o

heap: $(OBJECTS)
	$(CC) $(OBJECTS) -o heap

.cpp.o: functions.h
	$(CC) -c $*.cpp

clean:
	-rm *.o
