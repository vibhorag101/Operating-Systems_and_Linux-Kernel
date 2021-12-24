#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
void getRandomData(char myData[8])
{
    FILE *ptr = fopen("/dev/urandom", "r");
    fread(myData, 1, 8, ptr);
}
int main()
{
    while (1)
    {
        syscall(450);
        char myData[8];
        getRandomData(myData);
        syscall(448, myData);
        for (int i = 0; i < 8; i++)
        {
            printf("P wrote %d\n", myData[i]);
        }
        sleep(2);
    }


    return 0;
}