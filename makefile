GCC = gcc



all: main

main: main.o chiffrement.o
	${GCC} -o main main.o chiffrement.o

chiffrement.o: chiffrement.c chiffrement.h
		${GCC} -o chiffrement.o -c chiffrement.c

main.o:	main.c
	${GCC} -o main.o -c main.c

clean:	main.c
	rm -r *.o
