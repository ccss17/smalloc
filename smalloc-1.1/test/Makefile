override CFLAGS += -g -ggdb
COMPILE = -I.. -L.. -lsm

all: test1 test2 test3 test4

test1: test1.c
	gcc $(COMPILE) $? -o $@

test2: test2.c
	gcc $(COMPILE) $? -o $@

test3: test3.c
	gcc $(COMPILE) $? -o $@

test4: test4.c
	gcc $(COMPILE) $? -o $@
	gcc -I../include1.0 -L.. -lsm1.0 $? -o $@1.0

clean:
	if test -f test1; then rm test1; fi
	if test -f test2; then rm test2; fi
	if test -f test3; then rm test3; fi
	if test -f test4; then rm test4; fi
