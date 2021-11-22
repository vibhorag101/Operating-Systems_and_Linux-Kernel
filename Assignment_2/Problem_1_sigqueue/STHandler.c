#include <stdio.h>
#include <stdlib.h>
#include <bits/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
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
    while (1)
    {
        pause();
    }
    
    return 0;
}
void alarmHandler(){
    uint64_t totalClock = rdtsc();
    int elapsedTime = (totalClock)/(2400000000);
    union sigval data;
    data.sival_int = elapsedTime;
    sigqueue(pidS1,SIGTERM,data);
}