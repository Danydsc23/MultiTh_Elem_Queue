CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Werror -fext-numeric-literals

SOURCES = Queue.cpp main_file.cpp 
HEADERS= Queue.h
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = queueThreads

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

