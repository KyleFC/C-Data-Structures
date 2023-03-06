#include "stacklib.h"

int isEmpty(stack **st)
{
    //no bool values in C so we use 1 and 0
    stack *temp = *st;
    if (temp->tail == NULL)
    //if the tail is NULL then there is nothing in the stack.
    {
        return 1;
    }
    return 0;
}

node *peek(stack **st)
//return int rather than node *
{
    return (*st)->tail;
}

void push(stack **st, int n)
{
    stack *temp = *st;
    addToEnd(&temp, n);
}

int pop(stack **st)
{
    stack *tempL = *st;
    if (tempL->tail == NULL)
    {
        printf("This stack is already empty.\n");
        return -1;
    }
    node *temp = tempL->tail;
    int data = temp->data;
    removeLast(&tempL);
    free(temp);
    return data;
}

void removeLast(stack **list)//, node **head, node **tail)
{
    //use unlink node
    stack *temp = *list;
    node *curr = temp->tail;
    if (curr == NULL)
    //make sure the starting node isn't null
    {
        return;
    }

    else if (curr->prev == NULL )
    {
        temp->head = NULL;
        temp->tail = NULL;
        free(curr);
        curr = NULL;
        return;
    }

    node *end = curr->prev;
    end->next = NULL;
    //make sure the last node has next as NULL
    free(curr);
    curr = NULL;
    temp->tail = end;
}

void addToEnd(linkedlist** list, int data)//, node** head, int data) 
//**head so that this function can modify the original
{
    linkedlist *temp = *list;
    node *new = (node*) malloc(sizeof(node));
    //make a pointer called new. It will hold the address of the new memory location we reserved
    //(node*) is a typecast so that this void pointer turns into a node pointer
    new->data = data;
    new->prev = temp->head;
    //temp->tail
    new->next = NULL;
    //assign data to the variables within the new node

    if (temp->head == NULL)
    {
        temp->head = new;
        //if there isn't a head in the linked list yet
        //then make one and end the function
        return;
    }

    node* end = temp->head;
    while (end->next != NULL)
    //loop through the list until we reach the end
    {
        end = end->next;
    }
    //temp->tail->next = new;
    end->next = new;
    //set the 2nd to last node to have the new node as next
    new->prev = end;
    //duplicate line
    //set the last node to have the 2nd to last as prev
    temp->tail = new;
}
