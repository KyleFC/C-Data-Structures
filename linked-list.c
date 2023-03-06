#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.h"

void addToEnd(linkedlist** list, int data)//, node** head, int data) 
//**head so that this function can modify the original
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

void removeLast(linkedlist **list)//, node **head, node **tail)
{
    //use unlink node
    linkedlist *temp = *list;
    node *curr = temp->tail;
    if (curr == NULL)
    //make sure the starting node isn't null
    {
        return;
    }
    else if (curr->prev == NULL )
    {
        temp->count -= 1;
        temp->head = NULL;
        temp->tail = NULL;
        free(curr);
        curr = NULL;

        return;
    }
    temp->count -= 1;

    node *end = curr->prev;
    end->next = NULL;
    //make sure the last node has next as NULL
    free(curr);
    curr = NULL;
    temp->tail = end;
}

void removeFirst(linkedlist **list)//, node **head, node **tail)
//use unlink node
{
    linkedlist *temp = *list;
    node *curr = (*list)->head;
    if (curr == NULL)
    //make sure the starting node isn't null
    {
        return;
    }
    else if (curr->next == NULL )
    {
        temp->count -= 1;
        temp->head = NULL;
        temp->tail = NULL;
        free(curr);
        curr = NULL;
        
        return;
    }
    curr->next->prev = NULL;
    temp->head = curr->next;
    //set the new head and set prev to NULL
    free(curr);
    curr = NULL;
    temp->count -= 1;
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

void unlinkNode(linkedlist **list, int n)
//return node *
{
    linkedlist *temp = *list;
    node *tempnode = findNode(&temp, n);

    if (tempnode->prev != NULL)
    {
        tempnode->prev->next = tempnode->next;
        temp->count -= 1;
    }

    if (tempnode->next != NULL)
    {
        tempnode->next->prev = tempnode->prev;
        temp->count -= 1;
    }

    //special cases for head or tail
    free(tempnode);
    //don't free if returning tempnode
    tempnode = NULL;
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