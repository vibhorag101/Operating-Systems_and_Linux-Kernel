#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
pid_t pidS1 =-1;
void alarmHandler();
int main(int argc, char const *argv[])
{
    struct itimerval SRTimer;
    pidS1= atoi(argv[1]);
    signal(SIGALRM,alarmHandler);
    SRTimer.it_interval.tv_sec=1;
    SRTimer.it_interval.tv_usec=100000;
    SRTimer.it_value = SRTimer.it_interval;
    int a = setitimer(ITIMER_REAL,&SRTimer,NULL);
    printf("The value is %d\n",a);
    printf("We are in SRHandler file pid of S1 is %s\n",argv[1]);
    printf("insider\n");
    return 0;
}
void alarmHandler(){
    printf("insider\n");
    kill(pidS1,SIGTERM);

}