#include "queuelib.h"

int isEmpty(linkedlist **qu)
{
    //no bool values in C so we use 1 and 0
    linkedlist *temp = *qu;
    if (temp->head == NULL)
    //if the tail is NULL then there is nothing in the stack.
    {
        return 1;
    }
    return 0;
}

void enqueue(linkedlist **qu, int n)
{
    linkedlist *temp = *qu;
    addToEnd(&temp, n);
}

int dequeue(linkedlist **qu)
{
    linkedlist *tempList = *qu;
    if (tempList->head == NULL)
    {
        printf("This queue is already empty.\n");
        return -1;
    }
    node *temp = tempList->head;
    int data = temp->data;
    removeFirst(&tempList);
    free(temp);
    return data;
}