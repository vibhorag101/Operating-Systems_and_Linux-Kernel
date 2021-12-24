#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
void writer(char myData[8])
{
}
int main()
{
    while (1)
    {
        char myData[8];
        syscall(449, myData);
        for (int i = 0; i < 8; i++)
        {
            printf("C read %d\n", myData[i]);
        }
        sleep(2);
    }

    return 0;
}