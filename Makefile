CC=gcc
CFLAGS=-Wall -Wextra
SRCS := linkedList.c main.c
INCLUDE := linkedList.h
PREFIX =/usr

all:debug

debug:clean
	$(CC) $(CFLAGS) -g -std=gnu11 -o linkedList linkedList.c main.c
stable:clean
	$(CC) $(CFLAGS) -O2 -o linkedList linkedList.c main.c
library:clean
	$(CC) $(CFLAGS) -fPIC -c linkedList.c
	$(CC) -shared -Wl,-soname,liblinkedList.so.1 -o liblinkedList.so.1.0
clean:
	rm -vfr *~ linkedList
