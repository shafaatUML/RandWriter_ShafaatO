CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic
LIB = -lboost_unit_test_framework
OBJECTS = TextWriter.o RandWriter.o test.o

all: TextWriter test

TextWriter: $(OBJECTS)
	$(CC) $(CFLAGS) -o TextWriter TextWriter.o RandWriter.o 

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o test test.o RandWriter.o $(LIB)

TextWriter.o: TextWriter.cpp
	$(CC) $(CFLAGS) -c TextWriter.cpp -o TextWriter.o

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o

RandWriter.o: RandWriter.cpp RandWriter.hpp
	$(CC) $(CFLAGS) -c RandWriter.cpp

lint:
	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir --root=. *

clean:
	rm *.o TextWriter test