FILES = main.cpp 
OUT = salpd
CC = g++
FLAGS = -Wall -std=c++17

default: clean build

clean:
	-rm salpd

build: $(FILES)
	$(CC) -o $(OUT) $(FILES) $(FLAGS)

.PHONY: default clean build
