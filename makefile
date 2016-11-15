CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -std=c99
OBJS = pointersorter.o
DEPS = pointersorter.h

all: pointersorter
	rm *.o

pointersorter : $(OBJS)
	$(CC) $(CFLAGS) $^ -o pointersorter

pointersorter.o: pointersorter.c pointersorter.h
	$(CC) $(CFLAGS) -c pointersorter.c

clean:
	rm pointersorter
