CC=gcc
CFLAGS=-Wall

all: main

fifo.o: fifo.c fifo.h
	$(CC) $(CFLAGS) -c fifo.c

main.o: main.c fifo.h
	$(CC) $(CFLAGS) -c main.c

main: fifo.o main.o
	$(CC) $(CFLAGS) fifo.o main.o -o main

clean:
	rm -f *.o main
