CC=gcc
CFLAGS=-Wall -Wextra

debug:clean
	$(CC) $(CFLAGS) -g -std=gnu11 -o linkedList linkedList.c main.c
stable:clean
	$(CC) $(CFLAGS) -O2 -o linkedList linkedList.c main.c
clean:
	rm -vfr *~ linkedList
