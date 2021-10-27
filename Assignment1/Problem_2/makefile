main: main.o asm.o funcA.o funcB.o funcC.o
	gcc -no-pie asm.o main.o funcA.o funcB.o funcC.o -o main

main.o: main.c
	gcc -c main.c

funcA.o: funcA.c
	gcc -c funcA.c

funcB.o: funcB.c
	gcc -c funcB.c -o funcB.o

funcC.o: funcC.c
	gcc -c funcC.c
asm.o: assembly.asm
	nasm -f elf64 -o asm.o assembly.asm
clean:
	$(RM) main main.o funcA.o funcB.o funcC.o asm.o