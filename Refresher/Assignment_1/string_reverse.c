#include <stdio.h>
void swap(char *ptr1, char *ptr2)
{
    char temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int sizeStr(char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
void reverse(char *str, int size)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        swap(&str[low], &str[high]);
        low++;
        high--;
    }
}
int main()
{
    printf("enter the string\n");
    char str[100];
    // scanf("%s", str);
    fgets(str,100,stdin);
    printf("original string is ");
    // printf("%s", str);
    puts(str);
    printf("\n");
    int size = sizeStr(str);
    reverse(str, size);
    printf("reversed string is ");
    // printf("%s", str);
    puts(str);
    printf("\n");
    return 0;
}
