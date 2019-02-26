CC = g++
SRC_DIR = src
_OBJECTS = heap.o create.o insert.o delete.o display.o
OBJECTS = $(patsubst %.o, $(SRC_DIR)/%.o, $(_OBJECTS))

echo:
	@echo $(_OBJECTS)
	@echo $(OBJECTS)

heap: $(OBJECTS)
	$(CC) $(OBJECTS) -o heap

$(SRC_DIR)/%.cpp.o: $(SRC_DIR)/functions.h
	$(CC) -c $<.cpp

clean:
	-rm $(SRC_DIR)/*.o heap
