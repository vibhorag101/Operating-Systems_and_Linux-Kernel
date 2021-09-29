target: sort BST_insert Balanced_BST clean

sort: sort.o
	gcc sort.o -o sort

sort.o: sort.c
	gcc -c sort.c

BST_insert: BST_insert.o
	gcc BST_insert.o -o BST_insert

BST_insert.o: BST_insert.c
	gcc -c BST_insert.c

Balanced_BST: Balanced_BST.o
	gcc Balanced_BST.o -o Balanced_BST

Balanced_BST.o: Balanced_BST.c
	gcc -c Balanced_BST.c

clean:
	rm *.o 

