main: main.c SRHandler STHandler
	gcc main.c -o main

SRHandler: SRHandler.c
	gcc SRHandler.c -no-pie -o SRHandler

STHandler: STHandler.c
	gcc STHandler.c -no-pie -o STHandler

clean:
	rm main SRHandler STHandler