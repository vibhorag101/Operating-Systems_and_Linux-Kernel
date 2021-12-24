#include <stdio.h>
#include <stdlib.h>
void getRandomData(char myData[8]){
    FILE *ptr = fopen("/dev/urandom","r");
    fread(myData,1,8,ptr);
}
void writer(char myData[8]){
    
}
int main()
{
    char myData[8];
    getRandomData(myData);
    for (int i = 0; i < 8; i++)
    {
        printf("%d\n",myData[i]);
    }
    
    return 0;
}