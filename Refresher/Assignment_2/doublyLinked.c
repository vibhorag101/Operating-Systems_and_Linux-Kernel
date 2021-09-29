// A simple C program to introduce
// a linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    int roll;
    int year;
    char course[50];
    struct Node *next;
    struct Node *prev;
};
void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("Name is ");
        puts(n->name);
        printf("roll number is %d", n->roll);
        printf("\n");
        printf("joining year is %d", n->year);
        printf("\n");
        printf("Course is ");
        puts(n->course);
        printf("\n");

        n = n->next;
    }
};

//we create linked list with 3 nodes
int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    strcpy(head->name, "Steve Smith");
    head->roll = 1;
    head->year = 2020;
    strcpy(head->course, "CSAM");
    head->next = second; // Link first node with
    head->prev = NULL;

    // assign data to second node
    strcpy(second->name, "Bruce Banner");
    second->roll = 2;
    second->year = 2020;
    strcpy(second->course, "CSE");
    second->next = third;
    second->prev = head;

    strcpy(third->name, "Tony Stark");
    third->roll = 3;
    third->year = 2020;
    strcpy(third->course, "CSAI");
    third->next = NULL;
    printList(head);
    second->prev = second;

    return 0;
}
