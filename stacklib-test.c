#include "stacklib.c"

int main()
{
    int testFailure = 0;
    printf("START STACK TEST\n");
    stack *testStack = (stack*) malloc(sizeof(stack));
    testStack->tail = NULL;
    testStack->head = NULL;
    if (isEmpty(&testStack) == 1)
    {
        printf("isEmpty(): PASSED\n");
    } else
    {
        printf("isEmpty(): FAILED\n");
        testFailure = 1;
    }
    push(&testStack, 5);
    push(&testStack, 10);
    push(&testStack, 0);
    printf("Pushed items successfully\n");
    if (peek(&testStack)->data == 0)
    {
        printf("peek(): PASSED (1/2)\n");
    } else
    {
        printf("peek(): FAILED (1/2)\n");
        testFailure = 1;
    }
    if (pop(&testStack) == 0)
    {
        printf("pop(): PASSED (1/3)\n");
    } else
    {
        printf("pop(): FAILED (1/3)\n");
        testFailure = 1;
    }
    if (peek(&testStack)->data == 10)
    {
        printf("peek(): PASSED (2/2)\n");
    } else
    {
        printf("peek(): FAILED (2/2)\n");
        testFailure = 1;
    }
    if (pop(&testStack) == 10)
    {
        printf("pop(): PASSED (2/3)\n");
    } else
    {
        printf("pop(): FAILED (2/3)\n");
        testFailure = 1;
    }
    if (pop(&testStack) == 5)
    {
        printf("pop(): PASSED (3/3)\n");
    } else
    {
        printf("pop(): FAILED (3/3)\n");
        testFailure = 1;
    }
    printf("Attempting pop() on empty stack...  ");
    pop(&testStack);
    if (testFailure == 0)
    {
        printf("ALL TESTS PASSED\n");
    } else
    {
        printf("UNIT TEST FAILURE\n");
    }
}