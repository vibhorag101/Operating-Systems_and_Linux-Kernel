main: P1 P2 cleanFifo main.c
	gcc main.c -o main

P1: P1.c
	gcc P1.c -o P1
P2: P2.c
	gcc P2.c -o P2

cleanFifo:
	rm -f fifoString fifoIndex
clean:
	rm -f fifoString fifoIndex P1 P2