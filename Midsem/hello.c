#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
int count;
count=write(1,"hello\n",50);
printf("Total bytes written: %d\n",count);
}