#include <stdlib.h>
#include <stdio.h>
int main(void){

    int a=2,*b =NULL;
    b=&a;
    printf("%p\n",b);
    printf("%p\n",b+1);
    printf("%p\n",(char *)b+1);
    printf("%p\n",(void *)b+1);
}