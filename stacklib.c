#include "stacklib.h"
#include "linked-list.c"


/*
 * @brief: This returns whether or not the stack is empty
 * @param: the stack
 * @return:1 or 0
 */

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

/*
 * @brief: This looks at the last node in the stack
 * @param: the node
 * @return: int that of the node
 */

node *peek(stack **st)
//return int rather than node *
{
    return (*st)->tail;
}

/*
 * @brief: This deletes the node on the top of the stack
 * @param: the stack
 * @return: the new tail
 */

void push(stack **st, int n)
{
    stack *temp = *st;
    addToEnd(&temp, n);
}

/*
 * @brief: This adds a new node to the top of the stack
 * @param: the stack
 * @return: the new tail
 */

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
