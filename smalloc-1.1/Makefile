override CFLAGS += -g -ggdb
CC=gcc

all: libsm libsm1.0 tester

libsm: smalloc.c
	gcc -c -o $@.a $?

libsm1.0: smalloc1.0.c
	gcc -c -Iinclude1.0 -o $@.a $?

tester:
	make -C test

clean:
	if test -f libsm.a; then rm libsm.a; fi
	if test -f libsm1.0.a; then rm libsm1.0.a; fi
	make clean -C test
