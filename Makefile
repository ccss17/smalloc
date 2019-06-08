all:
	make -C smalloc-1.0
	make -C smalloc-1.1
	make -C smalloc-1.2

clean:
	make clean -C smalloc-1.0
	make clean -C smalloc-1.1
	make clean -C smalloc-1.2
