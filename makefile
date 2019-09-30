CFLAGS= -O -Wall -pedantic -std=c11
CC=gcc

source: source.o priorityQueue.o io.o cpu.o printStats.o

priorityQueue.o: priorityQueue.h a2.h io.h cpu.h

io.o: io.h a2.h priorityQueue.h

cpu.o: cpu.h a2.h priorityQueue.h

printStats.o: printStats.h a2.h

clean:
	rm -f *.o source

run:
	./source