#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
struct myData
{
    char stringArray[5][5];
    int indexArray[5];
    int Index;
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

int main(int argc, char const *argv[])
{
    int Index;
    int sock;
    struct sockaddr_un server;

    // creating a buffer to read data
    char buf[1024];

    // creating a new socket
    sock = socket(AF_UNIX, SOCK_STREAM, 0);

    // checking if an error occurred while creating a socket
    if (sock < 0)
    {
        perror("opening stream socket");
        exit(1);
    }
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, "/tmp/sock");

    // connecting to the socket created in the server
    // the file name is used to specify the correct socket
    if (connect(sock, (struct sockaddr *)&server, sizeof(struct sockaddr_un)) < 0)
    {
        close(sock);
        perror("connecting stream socket");
        exit(1);
    }
    struct myData data1;
    read(sock,(void*)&data1,100);
    printCharArray(data1.stringArray);
    printIndexArray(data1.indexArray);
    Index = data1.indexArray[4];
    printf("The highest index is %d\n",Index);

    close(sock);
    return (0);
}