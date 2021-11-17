#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copy_arr(char *p1,char p2[]){
    memcpy(p2,p1,sizeof(p1));
    memcpy(p2,"ABCD",4);
}
int main(){
    char arr1[100];
    char arr2[100];
    printf("enter a string\n");
    scanf("%s",arr1);
    copy_arr(arr1,arr2);
    printf("\n%s\n",arr2);
    return 0;

}