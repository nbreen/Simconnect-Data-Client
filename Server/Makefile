CC = gcc
CCFLAGS = -g -lpthread

all: server

server: server.c
	$(CC) server.c $(CCFLAGS) -o server

clean:
	rm server
