all: main.o get.o
	gcc -o program main.o get.o

main.o: main.c get.h
	gcc -c main.c

get.o: get.c get.h
	gcc -c get.c
