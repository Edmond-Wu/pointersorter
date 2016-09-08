CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -m32

pointersorter : pointersorter.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm pointersorter
