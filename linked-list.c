/*
 * @linked-list.c - linked list implementation
 * @brief: This file contains the methods needed to implement a linked list and selection sort
 *
 * @author: Kyle C, Timmy M, Nathan M
 * @date: March 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.h"


int count(linkedlist * list)
/*
 * @brief: This function returns the count of nodes in a linked list
 * @param: linked list
 * @return: the count
 */
{
    int total = list->count;
    printf("%d", total);
    return total;
}

void addToEnd(linkedlist** list, int data)
/*
 * @brief: This function creates a new node to the end of the linked list
 * @param: data - the data to be stored in the node
 * @return: None
 */
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
    end->next = new;
    //set the 2nd to last node to have the new node as next
    temp->tail = new;
}




void addToStart(linkedlist** list, int data)
/*
 * @brief: This function creates a new node to the beginning of the linked list
 * @param: data - the data to be stored in the node
 * @return: None
 */
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
/*
 * @brief: This prints the linked list
 * @param: linked list
 */
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
/*
 * @brief: This function removes the last node in the linked list
 * @param: data - the linked list
 * @return: the removed node
 */
{
    linkedlist *temp = *list;
    node *curr = temp->tail;
    
    if (curr == NULL)
    {
        return NULL;
    }

    unlinkNode(list, curr->data);

    return curr;
}

node *removeFirst(linkedlist **list)
/*
 * @brief: This function removes the first node in the linked list
 * @param: data - the linked list
 * @return:The removed node
 */
{
    linkedlist *temp = *list;
    node *curr = temp->head;
    
    if (curr == NULL)
    {
        return NULL;
    }

    unlinkNode(list, curr->data);

    return curr;
}



node *findNode(linkedlist **list, int n)
/*
 * @brief: This function finds the node at the given index n
 * @param: data - the linked list
 * @param: index - the index of the node, n
 * @return: the index n node
 */
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
/*
 * @brief: This inserts before index n
 * @param: data - information to be stored in the node
 * @param: index - the index of the node, n
 * @return: None
 */
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
/*
 * @brief: This inserts after index n
 * @param: data - information to be stored in the node
 * @param: index - the index of the node, n
 * @return: None
 */
{
    (*list)->count += 1;
    node *curr = *target;
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    new->prev = curr;
    new->next = curr->next;

    if (curr->next != NULL)
    {
        curr->next->prev = new;
    }
    else
    {
        (*list)->tail = new;
    }

    curr->next = new;
}

node* unlinkNode(linkedlist **list, int n)
/*
 * @brief: This function removes node at index n
 * @param: data - the linked list
 * @param: index - the index of the node, n
 * @return: the new linked list
 */
{
    node *tempnode = findNode(&*list, n);

    if (tempnode == (*list)->head)
    {
        (*list)->head = tempnode->next;
    }
    if (tempnode == (*list)->tail)
    {
        (*list)->tail = tempnode->prev;
    }

    if (tempnode->prev != NULL && tempnode->next != NULL)
    {
        tempnode->prev->next = tempnode->next;
        tempnode->next->prev = tempnode->prev;
    }
    else if (tempnode->next != NULL)
    {
        tempnode->next->prev = NULL;
        (*list)->head = tempnode->next; // redundant
    }
    else if (tempnode->prev != NULL)
    {
        tempnode->prev->next = NULL;
        (*list)->tail = tempnode->prev; // redundant
    }

    (*list)->count--;

    node *new = (node*) malloc(sizeof(node));
    new->data = tempnode->data;

    free(tempnode);

    return new;
}



void destroyList(linkedlist **list)
/*
 * @brief: This function destroys the linked list
 * @param: data - the linked list
 */
{
    node *curr = (*list)->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->count = 0;
}

//------------- Sorting---------------

void selectionSort(linkedlist **list)
/*
 * @brief: This function sorts the linked list
 *
 * Selection sort aims to sort the list by putting thr smallest value at the front
 * and repeating the process until the list is sorted. Its an O(n^2) algorithm
 *
 * @param: linked list
 */
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