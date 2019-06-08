override CFLAGS += -g -ggdb

all: libsm

libsm: smalloc.c
	gcc -c -o $@.a $?
	make -C test

clean:
	if test -f libsm.a; then rm libsm.a; fi
	make clean -C test
