target: binarySearch swap cp string_reverse clean

binarySearch: binarySearch.o
	gcc binarySearch.o -o binarySearch

binarySearch.o: binarySearch.c
	gcc -c binarySearch.c

swap: swap.o
	gcc swap.o -o swap

swap.o: swap.c
	gcc -c swap.c

cp: cp.o
	gcc cp.o -o cp

cp.o: cp.c
	gcc -c cp.c

string_reverse: string_reverse.o
	gcc string_reverse.o -o string_reverse

string_reverse.o: string_reverse.c
	gcc -c string_reverse.c

clean:
	rm *.o 
