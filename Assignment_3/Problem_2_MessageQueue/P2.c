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
#include<sys/wait.h>
#include<unistd.h>
struct queueData
{
    long index;
    char mString[5];
};
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
int getMessage(int msgid){
    char stringArray[5][5];
    int indexArray[5];
    for (int i = 0; i < 5; i++)
    {
        struct queueData data;
        msgrcv(msgid,(void*)&data,10,0,0);
        strcpy(stringArray[i],data.mString);
        indexArray[i] = data.index;
    }
    printCharArray(stringArray);
    printIndexArray(indexArray);
    return(indexArray[4]);
}
void sendIndex(int msgid,int Index){
    struct queueData data;
    data.index = Index;
    msgsnd(msgid,(void*)&data,5,0);
}
int main(int argc, char const *argv[])
{
    int msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    int Index = getMessage(msgid);
    msgctl(msgid, IPC_RMID, NULL);
    msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    sendIndex(msgid,Index);
    usleep(400000);
    msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    Index = getMessage(msgid);
    msgctl(msgid, IPC_RMID, NULL);
    msgid = msgget((key_t)12345, 0666 | IPC_CREAT);
    sendIndex(msgid,Index);
    
    return 0;
}