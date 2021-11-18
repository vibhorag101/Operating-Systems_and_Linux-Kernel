#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
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
    printf("We are in SRHandler file\n");
    while (1)
    {
        pause();
    }
    
    return 0;
}
void alarmHandler(){
    uint64_t myTime = rdtsc();
    uint64_t elapsedTime = (myTime)/(2400000000);
    int elapsedHour= elapsedTime/3600;
    int elapasedMin = (elapsedTime%3600)/60;
    int elapsedSec = (elapsedTime%3600)%60;
    char timeStr[500];
    sprintf(timeStr,"Time Since Computer Started %d Hours %d Minutes %d Seconds",elapsedHour,elapasedMin,elapsedSec);
    printf("Alarm form ST\n");
    kill(pidS1,SIGTERM);
    printf("%s\n",timeStr);
}