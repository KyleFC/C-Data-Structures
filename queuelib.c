/*
 * @queuelib.c - queue implementation
 * @brief  This file contains the implementation of the queue library.
 *
 * authors: Kyle C, Timmy M, Nathan M
 * date: March 2022
 */

#include "queuelib.h"

/*
 * @brief: This boolean checks if the queue is empty
 * @param: the queue to be checked
 * @return: 1 or 0
 */

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

/*
 * @brief: This function adds a new node to the end of the queue
 * @param: the queue to be added to
 * @return: the new queue
 */

void enqueue(linkedlist **qu, int n)
{
    linkedlist *temp = *qu;
    addToEnd(&temp, n);
}

/*
 * @brief: This function removes the first node in the queue
 * @param: the queue to be removed from
 * @return: the new queue
 */

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