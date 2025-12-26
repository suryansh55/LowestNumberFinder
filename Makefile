CC = gcc

all: numfinder numfindermulti

numfinder: numfinder.o
	$(CC) -o numfinder numfinder.o -lm

numfinder.o: numfinder.c
	$(CC) -c numfinder.c

numfindermulti: numfindermulti.o
	$(CC) numfindermulti.o -o numfindermulti -lpthread 

numfindermulti.o: numfindermulti.c
	$(CC) -c numfindermulti.c

clean:
	rm -f *.o numfinder numfindermulti