FILES = main.cpp
OUT = salpd
CC = g++
FLAGS = -w -std=c++14

default: buildSQL build

build:
	$(CC) -c main.cpp $(FLAGS)
	$(CC) -c AllClass-odb.cxx $(FLAGS)
	$(CC) -o salpd main.o AllClass-odb.o -lodb-pgsql -lodb $(FLAGS)

buildSQL:
	odb -d pgsql --generate-query --generate-schema AllClass.hxx

connectDB:
	@#PGPASSWORD=ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8- psql -h elmer.db.elephantsql.com -d qxanfxzw -U qxanfxzw -p 5432
	@psql postgres://salpd:banana@127.0.0.1:5432/salpd

connectApp:
	@#./salpd --user qxanfxzw --database qxanfxzw --host elmer.db.elephantsql.com --port 5432 --password ccxuE7Ak3GIXiq05gcVT3vgvwJ7naT8-
	@./salpd --user salpd --database salpd --host localhost --port 5432 --password banana

resetDB:
	@psql postgres://salpd:banana@127.0.0.1:5432/salpd < AllClass.sql
	@psql postgres://salpd:banana@127.0.0.1:5432/salpd < Inicial.sql

clean:
	-rm *-odb*
	-rm *.o
	-rm AllClass.sql
	-rm ./-.s

.PHONY: default clean build buildSQL
