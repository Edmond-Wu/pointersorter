CC = gcc
CFLAGS = -g -Wall -pedantic -ansi

pointersorter : pointersorter.c
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm pointersorter
