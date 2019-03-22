CC = g++ 
DEBUG = -O

CFLAGS = $(DEBUG) -c

TARGETS = rand_tester

all: $(TARGETS)


# Link the object files:

rand_tester: main.o rng.o
	$(CC) -o $@ main.o rng.o


# Compile the C++ files into object files

tester.o: main.cpp rng.hpp
	$(CC) $(CFLAGS) main.cpp 

rng.o: rng.cpp rng.hpp
	$(CC) $(CFLAGS) rng.cpp 


# Remove all non-critical files with the command: %make clean

clean:
	rm -f *.o *~* *.a
	rm -f rand_tester
