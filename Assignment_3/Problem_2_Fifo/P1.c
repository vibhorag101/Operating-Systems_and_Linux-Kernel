#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
void getCharArrays(int Index, char toBeSent[5][5], char stringArray[50][5], int indexArr[])
{
    int j = 0;
    for (int i = Index; i < Index + 5; i++)
    {
        strcpy(toBeSent[j], stringArray[i]);
        indexArr[j] = i;
        j++;
    }
}
void printCharArray(char toBeSent[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", toBeSent[i]);
    }
}
void randomStringGenerator(char stringArray[50][5])
{
    srand(time(NULL));
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            stringArray[i][j] = rand() % 26 + 65;
        }
    }
}
int main()
{
    char stringArray[50][5] = {{0}};
    randomStringGenerator(stringArray);

    char toBeSent[5][5];
    int indexArr[5];
    if (mkfifo("fifoString", 0777) == -1)
    {
        printf("Error making a fifo\n");
    }
    if (mkfifo("fifoIndex", 0777) == -1)
    {
        printf("Error making a fifo\n");
    }

    {
        int fd = open("fifoString", O_WRONLY);
        getCharArrays(5, toBeSent, stringArray, indexArr);
        write(fd, toBeSent, sizeof(char) * 25);
        write(fd, indexArr, sizeof(int) * 5);
        close(fd);
        int fd2 = open("fifoIndex", O_WRONLY);
        write(fd2, indexArr, sizeof(int) * 5);
        close(fd2);
        fd = open("fifoString", O_RDONLY);
        int receivedIndex;
        read(fd, &receivedIndex, sizeof(int));
        printf("Received Index %d from P2\n", receivedIndex);
        close(fd);

        fd = open("fifoString", O_WRONLY);
        getCharArrays(receivedIndex + 1, toBeSent, stringArray, indexArr);
        write(fd, toBeSent, sizeof(char) * 25);
        write(fd, indexArr, sizeof(int) * 5);
        close(fd);
        fd2 = open("fifoIndex", O_WRONLY);
        write(fd2, indexArr, sizeof(int) * 5);
        close(fd2);
        fd = open("fifoString", O_RDONLY);
        int received;
        read(fd, &received, sizeof(int));
        printf("Received Index %d from P2\n", received);
        close(fd);
    }

    return 0;
}