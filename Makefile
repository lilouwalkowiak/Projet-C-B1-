
CC = gcc-16
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic

build:
	$(CC) $(CFLAGS) main.c -o main

clean:
	rm -f main