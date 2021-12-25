#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
int main()
{
    pid_t pid1;
    printf("before fork()\n");
    if ((pid1=fork())>0)
    {
        waitpid(pid1,NULL,0);
    }
    else if(pid1==0){
        execl("/usr/bin/bash","bash",NULL);
        printf("done launching the shell");
    }
    else{
        perror("fork()");
    }
    
    return 0;
}