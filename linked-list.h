#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node 
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct linkedlist
{
    node *head;
    node *tail;
    int count;
} linkedlist;
//add count


void addToEnd(linkedlist**, int);
void addToStart(linkedlist**, int);
void printList(linkedlist**);
void removeLast(linkedlist**);
void removeFirst(linkedlist**);
node *findNode(linkedlist**, int);
void insertBefore(linkedlist**, node**, int);
void insertAfter(linkedlist**, node**, int);
void removeNode(linkedlist**, node**);