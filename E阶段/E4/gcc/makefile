CC = gcc
CFLAGS = -ggdb -Wall -Wextra

#all: ex1

PROGRAMS = $(patsubst %.c,%,$(wildcard *.c))

all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)

.PHONY: all clean
