#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
void printArr(float arr[3][3]){
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    float srcArr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float dstArr[3][3];
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            dstArr[i][j] = -1;
        }
    }
    printf("The source array is :\n");
    printArr(srcArr);
    printf("The destination array before syscall is :\n");
    printArr(dstArr);
    syscall(449, srcArr, dstArr, 36);
    printf("The destination array after the system call is :\n");
    printArr(dstArr);

    return 0;
}