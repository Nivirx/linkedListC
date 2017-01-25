CC=gcc
CFLAGS=-Wall -Wextra
SRCS := linkedList.c main.c
INCLUDE := linkedList.h
PREFIX =/usr

all: t

debug:clean
	$(CC) $(CFLAGS) -g -std=gnu11 -o linkedList linkedList.c main.c
stable:clean
	$(CC) $(CFLAGS) -O2 -o linkedList linkedList.c main.c
clean:
	rm -vfr *~ linkedList
