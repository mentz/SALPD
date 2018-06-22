FILES = main.cpp
OUT = salpd
CC = g++
FLAGS = -Wall -std=c++17

default: build

build:
	odb -d pgsql --generate-query --generate-schema AllClass.hxx
	c++ -c main.cpp -std=c++17
	c++ -c AllClass-odb.cxx -std=c++17
	c++ -o salpd main.o AllClass-odb.o -lodb-pgsql -lodb -std=c++17

connectDB:
	psql -h elmer.db.elephantsql.com -d qxanfxzw -U qxanfxzw -p 5432

connectApp:
	./salpd --user qxanfxzw --database qxanfxzw --host elmer.db.elephantsql.com --port 5432 --password ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8-

.PHONY: default clean build
