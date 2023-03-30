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
