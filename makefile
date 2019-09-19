CFLAGS= -O -Wall -pedantic -std=c11
CC=gcc

source: source.o readfile.o

source.o: readfile.h

readfile.o: readfile.h

clean:
	rm -f *.o source

run:
	./source