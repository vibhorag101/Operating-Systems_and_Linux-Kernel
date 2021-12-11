#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
struct queueData
{
    long index;
    char mString[5];
};
void sendMessage(int msgid, char stringArray[50][5], int index)
{
    char toBeSent[5][5];
    int indexArr[5];
    getCharArrays(index, toBeSent, stringArray, indexArr);
    for (int i = 0; i < 5; i++)
    {
        struct queueData data;
        data.index = indexArr[i];
        strncpy(data.mString, toBeSent[i], 5);
        msgsnd(msgid, (void *)&data, 10, 0);
    }
}

int main()
{
    char stringArray[50][5] = {{0}};
    randomStringGenerator(stringArray);
    int msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    sendMessage(msgid, stringArray, 5);
    return 0;
}