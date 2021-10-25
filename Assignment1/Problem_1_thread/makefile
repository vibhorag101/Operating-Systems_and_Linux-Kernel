averageThread: averageThread.o
	gcc -lpthread averageThread.o -o averageThread -lpthread
averageThread.o: averageThread.s
	gcc -c averageThread.s -o averageThread.o -lpthread
averageThread.s: averageThread.c
	gcc -S averageThread.c -lpthread
clean:
	${RM} averageThread averageThread.o averageThread.s
