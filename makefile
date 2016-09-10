CC = gcc
CFLAGS = -g -Wall -pedantic -ansi -std=c99

pointersorter : pointersorter.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm pointersorter
