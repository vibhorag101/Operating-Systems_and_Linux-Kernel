#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
int main(int argc, char const *argv[])
{
    printf("We are in SRHandler file pid of S1 is %s\n",argv[1]);
    pid_t pidS1= atoi(argv[1]);
    int k=kill(pidS1,SIGTERM);
    while (1)
    {
        int k=kill(pidS1,SIGTERM);
        printf("prgram is %d\n",k);
        sleep(5);
    }
    
    return 0;
}