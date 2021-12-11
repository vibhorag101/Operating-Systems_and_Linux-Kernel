#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void printCharArray(char toBeSent[5][5]){
    printf("The strings received from P1: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s ",toBeSent[i]);
    }
    printf("\n");
}
void printIndexArray(int toBeSent[5]){
    printf("The string index received from P1: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",toBeSent[i]);
    }
    printf("\n");
}
int main()
{
    int indexArr[5];
    char destArr[5][5];
    int fd = open("fifoString", O_RDONLY);
    read(fd, &destArr, sizeof(char)*25);
    close(fd);
    printCharArray(destArr);
    int fd2= open("fifoIndex",O_RDONLY);
    read(fd2,indexArr,sizeof(int)*5);
    close(fd2);
    printIndexArray(indexArr);
    int temp = indexArr[4];
    fd = open("fifoString", O_WRONLY);
    write(fd, &temp, sizeof(int));
    close(fd);


    fd = open("fifoString", O_RDONLY);
    read(fd, &destArr, sizeof(char)*25);
    close(fd);
    printCharArray(destArr);
    fd2= open("fifoIndex",O_RDONLY);
    read(fd2,indexArr,sizeof(int)*5);
    close(fd2);
    printIndexArray(indexArr);
    temp = indexArr[4];
    fd = open("fifoString", O_WRONLY);
    write(fd, &temp, sizeof(int));
    close(fd);

    return 0;
}