CC = gcc
LIBS = -lcheck
CFLAGS = -g -Wall -O -c

all: stack.o tests.o
	$(CC) $(LIBS) stack.o tests.o -o test

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c -o stack.o

tests.o: tests.c
	$(CC) $(CFLAGS) $(LIBS) tests.c -o tests.o

clean:
	rm -rf *.o test