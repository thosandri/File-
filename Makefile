
CC=gcc
CFLAGS=-O2

SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

EXE=test

$(EXE):$(OBJ)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJ)

purge:
	rm $(EXE)
