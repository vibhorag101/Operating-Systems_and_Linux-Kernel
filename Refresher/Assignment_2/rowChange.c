#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    printf("the old array is \n");
    int **arrOut = (int **)calloc(6, sizeof(int *));
    arrOut[0] = (int *)calloc(7, sizeof(int));
    arrOut[1] = (int *)calloc(4, sizeof(int));
    arrOut[2] = (int *)calloc(6, sizeof(int));
    arrOut[3] = (int *)calloc(3, sizeof(int));
    arrOut[4] = (int *)calloc(7, sizeof(int));
    arrOut[5] = (int *)calloc(2, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
    {
        arrOut[0][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        arrOut[1][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        arrOut[2][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        arrOut[3][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 7; i++)
    {
        arrOut[4][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        arrOut[5][i] = rand() % 10 + 1;
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");

    int row, change;
    printf("enter the row in which you want to change\n");
    scanf("%d", &row);
    printf("enter the new number of rows\n");
    scanf("%d", &change);
    arrOut[row] = realloc(arrOut[row], change * sizeof(int));
    int size[6]= {7,4,6,3,7,2};
    size[row]=change;

    for (int i = 0; i < change; i++)
    {
        arrOut[row][i] = rand() % 10 + 1;
    }
    for (int i = 0; i <size[0]; i++)
    {
        printf("%d ", arrOut[0][i]);
    }
    printf("\n");
    for (int i = 0; i <size[1]; i++)
    {
        printf("%d ", arrOut[1][i]);
    }
    printf("\n");
    for (int i = 0; i < size[2]; i++)
    {
        printf("%d ", arrOut[2][i]);
    }
    printf("\n");
    for (int i = 0; i < size[3]; i++)
    {
        printf("%d ", arrOut[3][i]);
    }
    printf("\n");
    for (int i = 0; i < size[4]; i++)
    {
        printf("%d ", arrOut[4][i]);
    }
    printf("\n");
    for (int i = 0; i < size[5]; i++)
    {
        printf("%d ", arrOut[5][i]);
    }
    for (int i = 0; i < 6; i++)
    {
        free(arrOut[i]);
    }

    return 0;
}