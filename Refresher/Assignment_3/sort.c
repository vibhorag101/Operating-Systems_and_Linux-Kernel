#include <stdio.h>
#include <stdio.h>
#include <string.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{

    printf("enter the number of elements in the array\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("enter the elements for the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int opType;
    printf("Enter s for selection sort and b for bubble sort\n");
    scanf(" %c", &opType);

    if (opType == 's')
        selectionSort(arr, n);
    else if (opType == 'b')
        bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
