#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *readFile, *writeFile;
    char filePath[100];
    scanf("%s", filePath);
    readFile = fopen(filePath, "r");
    if (readFile == NULL)
    {
        printf("Invalid source path");
        exit(0);
    }
    scanf("%s", filePath);
    writeFile = fopen(filePath, "w");
    if (readFile == NULL)
    {
        printf("Invalid destination path");
        exit(0);
    }
    char reqBuffer[1];
    while (fread(reqBuffer, sizeof(reqBuffer), 1, readFile) == 1)
    {
        fwrite(reqBuffer, sizeof(reqBuffer), 1, writeFile);
    }

    return 0;
}