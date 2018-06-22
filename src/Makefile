FILES = main.cpp
OUT = salpd
CC = g++
FLAGS = -w -std=c++17

default: build

build:
	c++ -c main.cpp $(FLAGS)
	c++ -c AllClass-odb.cxx $(FLAGS)
	c++ -o salpd main.o AllClass-odb.o -lodb-pgsql -lodb $(FLAGS)

buildSQL:
	odb -d pgsql --generate-query --generate-schema AllClass.hxx

connectDB:
	PGPASSWORD=ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8- psql -h elmer.db.elephantsql.com -d qxanfxzw -U qxanfxzw -p 5432

connectApp:
	./salpd --user qxanfxzw --database qxanfxzw --host elmer.db.elephantsql.com --port 5432 --password ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8-

.PHONY: default clean build
