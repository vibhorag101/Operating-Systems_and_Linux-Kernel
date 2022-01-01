#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <mutex.h>
pthread_t philosopher[5];
sem_t forks[5];
sem_t sauceBowls[4];
pthread_mutex_t waiter;
void philosopherAction(void *philosopherIndex){
    int philosopherArrived = *((int *)philosopherIndex);
    pthread
}
int main()
{
    pthread_mutex_init(&waiter,NULL);
    //creating forks 
    for (int i = 0; i < 5; i++)
    {
        sem_init(&forks[i],0,1);
    }
    //creating bowls
    for (int i = 0; i < 4; i++)
    {
        sem_init(&sauceBowls[i],0,1);
    }

    for (int i = 0; i < 5; i++)
    {
        
    }
    

    
       
    return 0;
}