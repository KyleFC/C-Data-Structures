#ifndef st_header
#define st_header

#include "linked-list.h"

typedef linkedlist stack;

int isEmpty(stack **st);
node *peek(stack **st);
void push(stack **st, int n);
int pop(stack **st);

#endif