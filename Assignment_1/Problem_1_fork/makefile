averageFork: averageFork.o
	gcc averageFork.o -o averageFork
averageFork.o: averageFork.s
	gcc -c averageFork.s -o averageFork.o
averageFork.s: averageFork.c
	gcc -S averageFork.c
clean:
	${RM} averageFork averageFork.o averageFork.s