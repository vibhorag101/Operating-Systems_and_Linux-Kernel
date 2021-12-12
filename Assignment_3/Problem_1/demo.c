#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
void printArr(float arr[3][3])
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    u_int64_t timeSliceEarlier;
    u_int64_t timeSliceAfter;
    int pid = fork();
    if (pid > 0)
    {
        printf("Inside the parent process\n");
        wait(NULL);
    }
    else
    {
        printf("Inside the child and call delayProcess\n");
        int procesPid = getpid();
        unsigned long dataSize = sizeof(u_int64_t);
        int a = syscall(449,4,procesPid,&timeSliceEarlier,&timeSliceAfter,8);
        if (a == -1)
        {
            printf("error in syscall\n");
        }
        else
        {
            printf("The vruntime alloted before system call %u\n",timeSliceEarlier);
            printf("The vruntime alloted after system call %u\n",
            timeSliceAfter);
        }
    }

    return 0;
}