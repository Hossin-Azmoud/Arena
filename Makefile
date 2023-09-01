CC=gcc
CFLAGS=-o main
SRC=./src/*.c

all: main

main:
	$(CC) $(CFLAGS) $(SRC)

clean:
	rm main
