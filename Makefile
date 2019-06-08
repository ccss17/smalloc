all:
	make -C smalloc-1.0
	make -C smalloc-1.1

clean:
	make clean -C smalloc-1.0
	make clean -C smalloc-1.1
