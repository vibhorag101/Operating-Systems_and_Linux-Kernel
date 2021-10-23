main: main.o funcA.o funcB.o funcC.o
	gcc -no-pie main.o funcA.o funcB.o funcC.o -o main

main.o: main.c
	gcc -c main.c

funcA.o: funcA.c
	gcc -c funcA.c

funcB.o: funcB.c
	gcc -c funcB.c

funcC.o: funcC.c
	gcc -c funcC.c

clean:
	rm *.o