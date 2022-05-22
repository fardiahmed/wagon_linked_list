CC = gcc
CFLAGS = -std=c99 -Wall -lm


C_SRCS = $(wildcard ./*.c)
C_OUTS = $(patsubst %.c, %, $(C_SRCS))

.PHONY: clean

all: $(C_OUTS) 

%.out : %.c
	$(CC) $(CFLAGS) $< -o $@



clean:
	$(RM) $(C_OUTS) 
