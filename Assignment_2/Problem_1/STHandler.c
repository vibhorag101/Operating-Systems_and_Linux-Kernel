#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include "external.h"
#define INTERVAL 4000
unsigned c,d;
int randTime;
pid_t pidS1 =-1;
void alarmHandler();
int main(int argc, char const *argv[])
{
    struct itimerval SRTimer;
    pidS1= atoi(argv[1]);
    signal(SIGALRM,alarmHandler);
    SRTimer.it_value.tv_sec= INTERVAL/1000;
    SRTimer.it_value.tv_usec=(INTERVAL*1000) % 1000000;
    SRTimer.it_interval = SRTimer.it_value;
    int a = setitimer(ITIMER_REAL,&SRTimer,NULL);
    printf("We are in SRHandler file\n");
    while (1)
    {
        pause();
    }
    
    return 0;
}
void alarmHandler(){
    asm volatile("rdtsc" : "=a" (c), "=d" (d));
    asm("mov %rax, randTime");
    printf("Alarm form ST %d\n",c);
    kill(pidS1,SIGTERM);
}