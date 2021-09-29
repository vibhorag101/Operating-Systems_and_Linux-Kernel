#include <stdio.h>
int binarySeach(int arr[], int n, int size)
{
    printf("the size of the array is %d\n",sizeof(*arr) / sizeof(arr[0]));
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            return (mid);
        }
        else if (arr[mid] > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (-1);
}
int main()
{
    int n, search;
    printf("enter the number of elements in the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element to be searched\n");
    scanf("%d", &search);
    int index = binarySeach(arr, search, n);
    if (index == -1)
    {
        printf("element not present in the array");
    }
    else
    {
        printf("the elements index is ");
        printf("%d", index);
    }
    return 0;
}
