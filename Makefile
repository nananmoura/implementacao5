

CC = gcc
CFLAGS = -Wall -Wextra -pthread -O2

ifneq ($(wildcard teste.c),)
all: sync_car

sync_car: sync_car.c sync_car.h teste.c
	$(CC) $(CFLAGS) -o sync_car sync_car.c teste.c
else
all: sync_car.o

sync_car.o: sync_car.c sync_car.h
	$(CC) $(CFLAGS) -c sync_car.c
endif

clean:
	rm -f sync_car sync_car.o

.PHONY: all clean

