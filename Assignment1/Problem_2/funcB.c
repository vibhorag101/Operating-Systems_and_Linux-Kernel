#include "function.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char charBin[30];
void funcB(char binString[100]){
    printf("We are in function B now\n");

    char *ptrTemp;

    char octalStrings[100][100];
    char temp[8];
    for (int i = 0; i < 8; i++)
    {
        strncpy(octalStrings[i], &binString[i * 8], 8);
    }

    for (int j = 0; j < 8; j++)
    {
        charBin[j] = strtol(octalStrings[j], &ptrTemp, 2);
    }
    charBin[8] =10;
    register char *arg2 asm("rsi") = charBin;
    asm("mov $1, %rax; mov $1, %rdi; mov $14, %rdx; syscall;");
    printf("Modifying the function Stack\n");
    // stackModify();
    modifyStack();
    return;
}
