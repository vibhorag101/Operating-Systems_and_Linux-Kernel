#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/stat.h>
float averageArrSecA[10];
float averageArrSecB[10];
void *getAverageSectionA(void *str)
{
    char *strA = (char *)str;
    char *endPtr;
    char myBuf[100];
    int assignmentSum[100];
    char assignmentAv[50];
    char assignmentAVStr[50][50];
    char tmp[100];
    char sectionA[5] = "A";
    char sectionB[5] = "B";
    char delim[5] = ",";
    char dataStrLine[100][1000];
    int openFile, newFile;
    int sectionACount = 0;
    ssize_t readerByte;

    openFile = open("student_record.csv", O_RDWR);
    int rowCounter = 0;
    while (1)
    {
        while (1)
        {
            readerByte = read(openFile, myBuf, 1);
            if (readerByte == 0)
            {
                goto end;
            }
            else if (myBuf[0] == '\n')
            {
                break;
            }
            else
            {
                strcat(dataStrLine[rowCounter], myBuf);
            }
        }
        rowCounter++;
    }
end:;

    for (int i = 1; i < rowCounter; ++i)
    {
        char tokenData[100][100];
        char *token = strtok(dataStrLine[i], delim);
        int tokenCounter = 0;
        while (token != NULL)
        {
            strcpy(tokenData[tokenCounter], token);
            token = strtok(NULL, delim);
            tokenCounter++;
        }
        if (strcmp(tokenData[1], sectionA) == 0)
        {
            sectionACount++;
            for (int j = 0; j < 6; ++j)
            {
                assignmentSum[j] += (int)strtol(tokenData[j + 2], &endPtr, 10);
            }
        }
    }
    // float averageArrSecA[10];
    for (int i = 0; i < 6; ++i)
    {
        averageArrSecA[i] = (float)assignmentSum[i] / (float)(sectionACount);
    }
    for (int i = 0; i < 6; ++i)
    {
        sprintf(assignmentAVStr[i], "%0.2f", averageArrSecA[i]);
    }

    // for (int i = 0; i < 6; ++i)
    // {
    //     printf("The Section A average of Assignment ");
    //     printf("%d ", i + 1);
    //     printf("is ");
    //     printf("%s", assignmentAVStr[i]);
    //     printf("\n");
    // }
    char newLine[10] = "\n";
    char comma[20] = ",";
    char Section[90] = "Section,Assignment 1,Assignment 2,Assignment 3,Assignment 4,Assignment 5,Assignment 6\nA,";
    strcat(strA, Section);
    for (int i = 0; i < 5; ++i)
    {
        strcat(strA, assignmentAVStr[i]);
        strcat(strA, comma);
    }
    strcat(strA, assignmentAVStr[5]);
    strcat(strA, newLine);
    close(openFile);
}

void *getAverageSectionB(void *str)
{
    char *strB = (char *)str;
    char *endPtr;
    char myBuf[100];
    int assignmentSum[100];
    // char assignmentAv[50];
    char assignmentAVStr[50][50];
    char tmp[100];
    char sectionB[5] = "B";
    char delim[5] = ",";
    char dataStrLine[100][1000];
    int openFile, newFile;
    int sectionBcount = 0;
    ssize_t readerByte;

    openFile = open("student_record.csv", O_RDWR);
    int rowCounter = 0;
    while (1)
    {
        while (1)
        {
            readerByte = read(openFile, myBuf, 1);
            if (readerByte == 0)
            {
                goto end;
            }
            else if (myBuf[0] == '\n')
            {
                break;
            }
            else
            {
                strcat(dataStrLine[rowCounter], myBuf);
            }
        }
        rowCounter++;
    }
end:;

    for (int i = 1; i < rowCounter; ++i)
    {
        char tokenData[100][100];
        char *token = strtok(dataStrLine[i], delim);
        int tokenCounter = 0;
        while (token != NULL)
        {
            strcpy(tokenData[tokenCounter], token);
            token = strtok(NULL, delim);
            tokenCounter++;
        }
        if (strcmp(tokenData[1], sectionB) == 0)
        {
            sectionBcount++;
            for (int j = 0; j < 6; ++j)
            {
                assignmentSum[j] += (int)strtol(tokenData[j + 2], &endPtr, 10);
            }
        }
    }
    // float averageArrSecB[10];
    for (int i = 0; i < 6; ++i)
    {
        averageArrSecB[i] = (float)assignmentSum[i] / (float)(sectionBcount);
    }
    for (int i = 0; i < 6; ++i)
    {
        sprintf(assignmentAVStr[i], "%0.2f", averageArrSecB[i]);
    }

    // for (int i = 0; i < 6; ++i)
    // {
    //     printf("The Section B average of Assignment ");
    //     printf("%d ", i + 1);
    //     printf("is ");
    //     printf("%s", assignmentAVStr[i]);
    //     printf("\n");
    // }

    char newLine[10] = "\n";
    char comma[20] = ",";
    strcat(strB, "B,");
    for (int i = 0; i < 5; ++i)
    {
        strcat(strB, assignmentAVStr[i]);
        strcat(strB, comma);
    }
    strcat(strB, assignmentAVStr[5]);
    strcat(strB, newLine);
    close(openFile);
}

int main()
{
    int newFile;
    float combinedAverage[100];
    char assignmentCombinedAVStr[100][100];
    open("average.csv", O_CREAT, S_IRWXU);
    newFile = open("average.csv", O_RDWR);
    char *strA = (char *)calloc(1000, 1);
    char *strB = (char *)calloc(1000, 1);
    char *strC = (char *)calloc(1000, 1);
    pthread_t childThread;
    // the child thread calculates the average for the section B
    //parent thread does the same for section A.
    pthread_create(&childThread, NULL, &getAverageSectionB, (void *)strB);
    pthread_join(childThread, NULL);
    getAverageSectionA((void *)strA);

    for (int i = 0; i < 6; i++)
    {
        combinedAverage[i] = (averageArrSecA[i] + averageArrSecB[i]) / 2;
    }
    for (int i = 0; i < 6; ++i)
    {
        sprintf(assignmentCombinedAVStr[i], "%0.2f", combinedAverage[i]);
    }
    char newLine[10] = "\n";
    char comma[20] = ",";
    strcat(strC, "Combined,");
    for (int i = 0; i < 5; ++i)
    {
        strcat(strC, assignmentCombinedAVStr[i]);
        strcat(strC, comma);
    }

    strcat(strC, assignmentCombinedAVStr[5]);
    strcat(strC, newLine);
    write(newFile, strA, strlen(strA));
    write(newFile, strB, strlen(strB));
    write(newFile, strC, strlen(strC));
    
    printf("Averages written to average.csv file newly created\n");
}
