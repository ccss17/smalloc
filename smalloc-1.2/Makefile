override CFLAGS += -g -ggdb
CC=gcc

all: libsm tester

libsm: smalloc.c
	gcc -c -o $@.a $?

tester:
	make -C test

clean:
	if test -f libsm.a; then rm libsm.a; fi
	make clean -C test
