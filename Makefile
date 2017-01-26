CC=gcc
CFLAGS=-std=gnu11 -Wall -Wextra
SRCS := linkedList.c main.c
INCLUDE := linkedList.h
PREFIX =/usr

all:debug

debug:clean
	$(CC) $(CFLAGS) -Og -g -o linkedList linkedList.c main.c
stable:clean
	$(CC) $(CFLAGS) -O2 -o linkedList linkedList.c main.c
library:clean
	$(CC) $(CFLAGS) -fPIC -c linkedList.c
	$(CC) -shared -o liblinkedList.so linkedList.o
shared_bin:library
	$(CC) $(CFLAGS) -O2 -L$(shell pwd) -llinkedList -o linkedList main.c
clean:
	rm -vfr *~ linkedList
	rm -vfr *.o
	rm -vfr liblinkedList.so*
