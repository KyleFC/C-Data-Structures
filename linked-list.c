#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.h"

void addToEnd(linkedlist** list, int data)
{
    linkedlist *temp = *list;
    node *new = (node*) malloc(sizeof(node));
    //make a pointer called new. It will hold the address of the new memory location we reserved
    //(node*) is a typecast so that this void pointer turns into a node pointer
    new->data = data;
    new->prev = temp->tail;
    new->next = NULL;
    //assign data to the variables within the new node
    temp->count += 1;

    if (temp->tail == NULL)
    {
        temp->head = new;
        temp->tail = new;
        //if there isn't a tail in the linked list yet
        //then make one and end the function
        return;
    }

    node* end = temp->tail;
    while (end->next != NULL)
    //loop through the list until we reach the end
    {
        end = end->next;
    }
    end->next = new;
    //set the 2nd to last node to have the new node as next
    temp->tail = new;
}

void addToStart(linkedlist** list, int data)
{ 
    linkedlist *temp = *list;
    node *new = (node*) malloc(sizeof(node));
    //make a pointer called new. It will hold the address of the new memory location we reserved
    //(node*) is a typecast so that this void pointer turns into a node pointer
    new->data = data;
    new->prev = NULL;
    new->next = temp->head;
    //assign data to the variables within the new node
    temp->count += 1;

    if (temp->head == NULL)
    {
         temp->head = new;
        //if there isn't a head in the linked list yet
        //then make one and end the function
        return;
    }
    temp->head->prev = new;
    temp->head = new;
}

void printList(linkedlist **list)
{
    node *curr = (*list)->head;
    printf("%d items: ", (*list)->count);
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

node* removeLast(linkedlist **list)
{
    linkedlist *temp = *list;
    node *curr = temp->tail;
    
    if (curr == NULL)
    {
        return NULL;
    }

    temp->tail = curr->prev;
    curr->prev = NULL;
    temp->count -= 1;
    unlinkNode(list, curr->data);

    return curr;
}

node *removeFirst(linkedlist **list)
{
    linkedlist *temp = *list;
    node *curr = temp->head;
    
    if (curr == NULL)
    {
        return NULL;
    }

    temp->head = curr->next;
    curr->next = NULL;
    temp->count -= 1;
    unlinkNode(list, curr->data);

    return curr;
}

node *findNode(linkedlist **list, int n)
{
    node *curr = (*list)->head;
    while (curr != NULL)
    {
        if (curr->data == n)
        {
            return curr;
        }
        curr = curr->next;
    }
    printf("COULD NOT FIND NODE WITH VALUE %d\n", n);
    return NULL;
}

void insertBefore(linkedlist **list, node **target, int data)
{
    (*list)->count += 1;
    node *curr = *target;
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    new->prev = curr->prev;
    new->next = curr;

    if (curr->prev != NULL)
    {
        curr->prev->next = new;
    }

    curr->prev = new;
}

void insertAfter(linkedlist **list, node **target, int data)
{
    (*list)->count -= 1;
    node *curr = *target;
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    new->prev = curr;
    new->next = curr->next;

    if (curr->next != NULL)
    {
        curr->next->prev = new;
    }

    curr->next = new;
}

node* unlinkNode(linkedlist **list, int n)
{
    linkedlist *temp = *list;
    node *tempnode = findNode(&temp, n);

    if (tempnode == temp->head)
    {
        temp->head = tempnode->next;
    }
    else if (tempnode == temp->tail)
    {
        temp->tail = tempnode->prev;
    }
    else
    {
        if (tempnode->prev != NULL)
        {
            tempnode->prev->next = tempnode->next;
        }

        if (tempnode->next != NULL)
        {
            tempnode->next->prev = tempnode->prev;
        }
    }

    if (tempnode->prev != NULL || tempnode->next != NULL)
    {
        temp->count--;
    }

    tempnode->prev = NULL;
    tempnode->next = NULL;
    return tempnode;
}


void destroyList(linkedlist **list)
{
    linkedlist *temp = *list;
    while (temp->head != NULL)
    {
        removeLast(&temp);
    }
    temp->count = 0;
}
//------------- C ---------------
void selectionSort(linkedlist **list)
{
    node *curr = (*list)->head;
    while (curr->next != NULL)
    {
        //go through all values to find the minimum
        node *min = curr;
        node *temp = curr->next;
        while (temp != NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }

        int tempData = curr->data;
        curr->data = min->data;
        min->data = tempData;
        curr = curr->next;
        //we set curr's value to min and then make the next
        //node the starting node
    }
}