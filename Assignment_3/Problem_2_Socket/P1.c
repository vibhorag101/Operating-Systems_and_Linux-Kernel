#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define NAME "/tmp/sock"

struct myData
{
    char stringArray[5][5];
    int indexArray[5];
    int Index;
};

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
struct myData messageStructure(char stringArray[50][5], char toBeSent[5][5], int indexArray[5], int Index)
{
    struct myData data;
    getCharArrays(Index, toBeSent, stringArray, indexArray);
    memcpy(data.indexArray, indexArray, sizeof(int) * 5);
    memcpy(data.stringArray, stringArray, sizeof(char) * 25);
    return (data);
}

int main(int argc, char const *argv[])
{
    char stringArray[50][5] = {{0}};
    randomStringGenerator(stringArray);
    char toBeSent[5][5];
    int indexArr[5];
    int Index;
    int sock, msgsock, rval;
    struct sockaddr_un server;

    // creating a buffer to read data
    char buf[1024];

    // creating a new socket
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Socket make failed\n");
        unlink(NAME);
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, NAME);

    // binding the socket to the file
    if (bind(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_un)))
    {
        perror("binding stream socket");
        unlink(NAME);
        exit(1);
    }
    int option = 1;
    listen(sock, 5);
    msgsock = accept(sock, 0, 0);
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    if (msgsock == -1)
        perror("accept");
    else
    {

        struct myData data1 = messageStructure(stringArray, toBeSent, indexArr, 5);
        printCharArray(data1.stringArray);
        write(msgsock, (void *)&data1, 52);
    }

    close(msgsock);

    unlink(NAME);
    close(sock);
    return (0);
}