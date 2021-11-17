#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
int main(int argc, char** argv)
{
    printf("This is the first process\n");
    execl("./hello","./hello","5",NULL);
    printf("%d",errno);
    return 0;
}