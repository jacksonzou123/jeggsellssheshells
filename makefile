all: main.o get.o parse.o
	gcc -o program main.o get.o parse.o

main.o: main.c get.h
	gcc -c main.c

get.o: get.c get.h
	gcc -c get.c

parse.o: parse.c parse.h
	gcc -c parse.c

run:
	./program 
