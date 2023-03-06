#include "stacklib.c"

int main()
{
    //implement better tests
    printf("START STACK TEST\n");
    stack *testStack = (stack*) malloc(sizeof(stack));
    testStack->tail = NULL;
    testStack->head = NULL;
    printf("isEmpty = %d\n", isEmpty(&testStack));
    push(&testStack, 5);
    push(&testStack, 10);
    push(&testStack, 0);
    printf("push success\n");
    printf("peek = %d\n", peek(&testStack)->data);
    printf("pop = %d\n", pop(&testStack));
    printf("peek = %d\n", peek(&testStack)->data);
    pop(&testStack);
    pop(&testStack);
    pop(&testStack);
}