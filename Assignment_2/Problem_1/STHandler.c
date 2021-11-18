#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include "external.h"
#include <stdint.h>
#include <inttypes.h>
#define INTERVAL 4000
int randTime;
pid_t pidS1 =-1;
void alarmHandler();
uint64_t rdtsc () {
unsigned int lo , hi ;
__asm__ __volatile__ ( " rdtsc " : "=a " ( lo ) , "=d " ( hi ) ) ;
return (( uint64_t ) hi << 32) | (uint64_t)lo ;
}


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
    // asm("mov %rax, randTime");
    uint64_t myTime = rdtsc();
    // sleep(5);
    // uint64_t myTime2 = rdtsc();
    uint64_t elapsedTime = (myTime)/(2400000000);
    printf("Alarm form ST\n");
    printf("%" PRIu64 "\n", elapsedTime);
    kill(pidS1,SIGTERM);
}