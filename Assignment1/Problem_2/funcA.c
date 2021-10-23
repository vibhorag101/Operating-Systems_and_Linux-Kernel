#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void funcA(){
    printf("We are in function A now\n");
    printf("Enter the 64bit binary integer\n");
    char binString[100];
    scanf("%s",binString);
    funcB(binString);
    return;
}