#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
pid_t pidS1 = -1;
pid_t pidSR = -1;
pid_t pidST = -1;
void sigtermHandler();
int main()
{
    pidS1 = fork();
    if (pidS1==0)
    {
        signal(SIGTERM,sigtermHandler);
        while (1)
        {
            pause();
        }
        
        
    }
    else if(pidS1>0){
        char S1id[10];
        sprintf(S1id,"%d",pidS1);
        pidSR = fork();
        if(pidSR==0){
            execl("./SRHandler","./SRHandler",S1id,NULL);
        }
        else if(pidSR>0){
            pidST= fork();
            if (pidST==0)
            {
                execl("./STHandler","./STHandler",S1id,NULL);
            }
            waitpid(pidS1,NULL,0);
        }
    }
    
    return 0;
}
void sigtermHandler(){
    printf("We received a SIGTERM CALL\n");
}