all : add-nbo

add-nbo : add-nbo.o
	gcc -o add-nbo add-nbo.o

add-nbo.o : add-nbo.h add-nbo.c

clear :
	rm -f add-nbo
	rm -f *.o
