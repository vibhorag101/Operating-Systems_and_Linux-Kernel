LIBS += -lm
target: doublyLinked funcPointArr linkedList matrix rowChange sort clean

doublyLinked: doublyLinked.o
	gcc doublyLinked.o -o doublyLinked

doublyLinked.o: doublyLinked.c
	gcc -c doublyLinked.c

linkedList: linkedList.o
	gcc linkedList.o -o linkedList

linkedList.o: linkedList.c
	gcc -c linkedList.c

funcPointArr: funcPointArr.o
	gcc funcPointArr.o -o funcPointArr $(LIBS)

funcPointArr.o: funcPointArr.c
	gcc -c funcPointArr.c

matrix: matrix.o
	gcc matrix.o -o matrix

matrix.o: matrix.c
	gcc -c matrix.c

sort: sort.o
	gcc sort.o -o sort

sort.o: sort.c
	gcc -c sort.c

rowChange: rowChange.o
	gcc rowChange.o -o rowChange

rowChange.o: rowChange.c
	gcc -c rowChange.c

clean:
	rm *.o 
