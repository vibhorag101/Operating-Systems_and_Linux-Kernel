#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
void getRandomData(char myData[8]){
    FILE *ptr = fopen("/dev/urandom","r");
    fread(myData,1,8,ptr);
}
int main()
{
    syscall(450);
    char myData[8];
    getRandomData(myData);
    syscall(448,myData);
    for (int i = 0; i < 8; i++)
    {
        printf("sent %d\n",myData[i]);
    }

    
    return 0;
}