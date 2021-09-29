#include <stdio.h>
#include <math.h>
void add(int a, int b)
{
    printf("%d", a + b);
}
void sub(int a, int b)
{
    printf("%d", a - b);
}
void mul(int a, int b)
{
    printf("%d", a * b);
}
void div(int a, int b)
{
    printf("%d", a / b);
}
void exponent(int a, int b)
{
    printf("%lf", pow((double)a, (double)b));
}
int main()
{
    void (*arr[5])(int, int) = {add, sub, mul, div, exponent};
    int op, a, b;
    printf("enter 0 for add\n");
    printf("enter 1 for subtract\n");
    printf("enter 2 for multiply\n");
    printf("enter 3 for divide\n");
    printf("enter 4 for exponentiation\n");
    scanf("%d", &op);
    printf("enter first number\n");
    scanf("%d", &a);
    printf("enter second number\n");
    scanf("%d", &b);
    arr[op](a, b);

    return 0;
}
