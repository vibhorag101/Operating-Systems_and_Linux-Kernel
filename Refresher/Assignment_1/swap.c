#include <stdio.h>
#include <string.h>
void swap(int *arr1, int *arr2, int n)
{
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}
int main()
{
    char opType[10];
    printf("For swapping the arrays type arrays and for elements type element\n");
    scanf("%s", opType);
    if (strcmp(opType, "array") == 0)
    {
        printf("enter the number of elements in the array\n");
        int n;
        scanf("%d", &n);
        int arr1[n], arr2[n];
        printf("enter the elements for the first array\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr1[i]);
        }
        printf("enter the elements for the second array\n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr2[i]);
        }
        printf("array 1 before swap is ");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr1[i]);
            printf(" ");
        }
        printf("\n");
        printf("array 2 before swap is ");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr2[i]);
            printf(" ");
        }
        printf("\n");
        swap(arr1, arr2, n);
        printf("array 1 after swap is ");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr1[i]);
            printf(" ");
        }
        printf("\n");
        printf("array 1 after swap is ");
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr1[i]);
            printf(" ");
        }
        printf("\n");
    }
    else
    {
        int a, b;
        printf("enter first integer\n");
        scanf("%d", &a);
        printf("enter first integer\n");
        scanf("%d", &b);
        printf("value of a before swap is ");
        printf("%d\n", a);
        printf("value of b before swap is ");
        printf("%d\n", b);
        int temp = a;
        a = b;
        b = temp;
        printf("value of a after swap is ");
        printf("%d\n", a);
        printf("value of b after swap is ");
        printf("%d\n", b);
    }
    return 0;
}
