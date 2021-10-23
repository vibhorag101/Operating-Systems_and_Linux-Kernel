#include <stdlib.h>
#include <stdio.h>
#include "function.h"
void funcC(){
    printf("We are in function C\n");
    printf("exit by syscall\n");
    asm("mov $1, %rax;mov $0, %rbx; int $0x80");
}