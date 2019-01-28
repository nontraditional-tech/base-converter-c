CC=gcc
CFLAGS=-I .
DEPS=math.h decBinaryConvert.h
OBJ=main.c decBinaryConvert.c

LDFLAGS= -lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS) 

decBinaryConvert: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
