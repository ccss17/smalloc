override CFLAGS += -g -ggdb

all: build/ build/libsm-1.0.a build/libsm-1.1.a build/test

build/: build/
	if ! test -d build; then mkdir build; fi

build/libsm-1.0.a: smalloc-1.0/smalloc.c
	make -C smalloc-1.0

build/libsm-1.1.a: smalloc-1.1/smalloc.c
	make -C smalloc-1.1

build/test: test/test1.c test/test2.c test/test3.c 
	make -C test

clean:
	if test -d build; then rm -rf build; fi
