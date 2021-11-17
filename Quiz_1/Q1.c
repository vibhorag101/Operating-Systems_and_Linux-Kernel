#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char add(float a,float b)
{
return (int)(round (a)+round (b)) ;
}

int main()
{
    printf("%d\n",add(1,2));
    return 0;
}