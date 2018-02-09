CC=g++ -std=c++11
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Graph.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prog2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


