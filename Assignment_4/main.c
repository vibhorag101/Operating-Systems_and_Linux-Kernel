#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (pid>0)
    {
        usleep(1000);
        execl("./C","./C",NULL);

    }
    else{
        execl("./P","./P",NULL);
    }
    
    return 0;
}