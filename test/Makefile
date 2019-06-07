override CFLAGS += -g -ggdb
CC=gcc
V1.0_COMPILE = -I../smalloc-1.0 -L../build -lsm-1.0
V1.0_TARGET = build/test1-1.0 build/test2-1.0 build/test3-1.0 
V1.1_COMPILE = -I../smalloc-1.1 -L../build -lsm-1.1
V1.1_TARGET = build/test1-1.1 build/test2-1.1 build/test3-1.1 

all: $(V1.0_TARGET) $(V1.1_TARGET)

build/test1-1.0: test1.c
	$(CC) $(V1.0_COMPILE) $? -o ../$@

build/test2-1.0: test2.c
	$(CC) $(V1.0_COMPILE) $? -o ../$@

build/test3-1.0: test3.c
	$(CC) $(V1.0_COMPILE) $? -o ../$@

build/test1-1.1: test1.c
	$(CC) $(V1.1_COMPILE) $? -o ../$@

build/test2-1.1: test2.c
	$(CC) $(V1.1_COMPILE) $? -o ../$@

build/test3-1.1: test3.c
	$(CC) $(V1.1_COMPILE) $? -o ../$@
