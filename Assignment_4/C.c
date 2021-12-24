#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
void writer(char myData[8]){
    
}
int main()
{
    char myData[8];
    syscall(449,myData);
    for (int i = 0; i < 8; i++)
    {
        printf("recieved %d\n",myData[i]);
    }

    
    return 0;
}