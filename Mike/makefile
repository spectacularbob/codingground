# Makefile
LDFLAGS=-lncurses

CC=g++
CFLAGS=-c
SOURCES=main.cpp character.cpp drawable.cpp world.cpp scenery.cpp dialog.cpp scene.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *.o
