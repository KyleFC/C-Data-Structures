#include "queuelib.h"

int main()
{
    //implement better tests
    printf("START QUEUE TEST\n");
    linkedlist *testQueue = (linkedlist*) malloc(sizeof(linkedlist));
    testQueue->tail = NULL;
    testQueue->head = NULL;
    printf("isEmpty = %d\n", isEmpty(&testQueue));
    enqueue(&testQueue, 5);
    enqueue(&testQueue, 10);
    enqueue(&testQueue, 0);
    printf("enqueue success\n");
    printf("dequeue = %d\n", dequeue(&testQueue));
    dequeue(&testQueue);
    dequeue(&testQueue);
    dequeue(&testQueue); //Should print error message
}