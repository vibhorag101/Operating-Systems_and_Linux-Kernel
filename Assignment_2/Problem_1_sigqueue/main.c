#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/types.h>
#include <inttypes.h>
pid_t pidS1 = -1;
pid_t pidSR = -1;
pid_t pidST = -1;
void sigtermHandler(int sig, siginfo_t *data, void *ptr);
int main()
{
    pidS1 = fork();
    if (pidS1 == 0)
    {
        struct sigaction action;
        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = &sigtermHandler;
        sigaction(SIGTERM, &action, NULL);
        while (1)
        {
            pause();
        }
    }
    else if (pidS1 > 0)
    {
        char S1id[10];
        sprintf(S1id, "%d", pidS1);
        pidSR = fork();
        if (pidSR == 0)
        {
            execl("./SRHandler", "./SRHandler", S1id, NULL);
        }
        else if (pidSR > 0)
        {
            pidST = fork();
            if (pidST == 0)
            {
                execl("./STHandler", "./STHandler", S1id, NULL);
            }
            waitpid(pidS1, NULL, 0);
        }
    }

    return 0;
}
void sigtermHandler(int sig, siginfo_t *info, void *ptr)
{
    int randNum = info->si_value.sival_int;
    int elapsedTime = info->si_value.sival_int;
    printf("S1 received a SIGTERM CALL\n");
    if (abs(elapsedTime) < 1000000)
    {
        int elapsedHour = elapsedTime / 3600;
        int elapasedMin = (elapsedTime % 3600) / 60;
        int elapsedSec = (elapsedTime % 3600) % 60;
        char timeStr[500];
        sprintf(timeStr, "Time Since Computer Started %d Hours %d Minutes %d Seconds", elapsedHour, elapasedMin, elapsedSec);
        printf("%s\n", timeStr);
    }
    else{
        printf("The random number is %d\n", randNum);
    }

}
