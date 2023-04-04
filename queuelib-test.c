#include "queuelib.c"

int main()
{
    int testFailure = 0;
    printf("START QUEUE TEST\n");
    linkedlist *testQueue = (linkedlist*) malloc(sizeof(linkedlist));
    testQueue->tail = NULL;
    testQueue->head = NULL;
    if (isEmpty(&testQueue) == 1)
    {
        printf("isEmpty(): PASSED\n");
    } else
    {
        printf("isEmpty(): FAILED\n");
        testFailure = 1;
    }
    enqueue(&testQueue, 5);
    enqueue(&testQueue, 10);
    enqueue(&testQueue, 0);
    printf("Enqueued items successfully\n");
    if (dequeue(&testQueue) == 5)
    {
        printf("dequeue(): PASSED (1/3)\n");
    } else
    {
        printf("dequeue(): FAILED (1/3)\n");
        testFailure = 1;
    }
    if (dequeue(&testQueue) == 10)
    {
        printf("dequeue(): PASSED (2/3)\n");
    } else
    {
        printf("dequeue(): FAILED (2/3)\n");
        testFailure = 1;
    }
    if (dequeue(&testQueue) == 0)
    {
        printf("dequeue(): PASSED (3/3)\n");
    } else
    {
        printf("dequeue(): FAILED (3/3)\n");
        testFailure = 1;
    }
    printf("Dequeueing from empty queue...  ");
    dequeue(&testQueue); //Should print error message
    if (testFailure == 0)
    {
        printf("ALL TESTS PASSED\n");
    } else
    {
        printf("UNIT TEST FAILURE\n");
    }
}