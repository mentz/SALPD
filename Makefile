default: clean build

clean: src/Makefile
	-rm salpd
	cd src && make clean

build:
	cd src && make && cp salpd ../salpd

.PHONY: default clean build
