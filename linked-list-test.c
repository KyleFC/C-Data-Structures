#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.c"

int main() 
{
    int testFailure = 0;
    printf("START MAIN\n");
    linkedlist *LL = (linkedlist*) malloc(sizeof(linkedlist));
    LL->head = NULL;
    LL->tail = NULL;
    printf("init linked list\n");
    //Test addToEnd()
    addToEnd(&LL, 4);
    addToEnd(&LL, 2);
    addToEnd(&LL, 3);

    if (LL->head->data == 4 && LL->tail->data == 3) 
    {
        printf("addToEnd(): PASSED\n");
    } else 
    {
        printf("addToEnd(): FAILED\n");
        testFailure = 1;
    }

    //Test printList
    printList(&LL);
    //Test addToStart()
    addToStart(&LL, 7);
    if (LL->head->data == 7 && LL->tail->data == 3) 
    {
        printf("addToStart(): PASSED\n");
    } else 
    {
        printf("addToStart(): FAILED\n");
        testFailure = 1;
    }
    printList(&LL);
    //Test findNode()
    node *foundNode = findNode(&LL, 2);
    if (foundNode->data == 2)
    {
        printf("findNode(): PASSED\n");
    } else
    {
        printf("findNode(): FAILED\n");
        testFailure = 1;
    }
    //Test unlinkNode
    unlinkNode(&LL, 2);
    if (findNode(&LL, 2) == NULL) 
    {
        printf("unlinkNode(): PASSED\n");
    } else 
    {
        printf("unlinkNode(): FAILED\n");
        testFailure = 1;
    }
    //Test selectionSort()
    selectionSort(&LL);
    printList(&LL);
    //Test removeFirst()
    removeFirst(&LL);
    if (LL->head->data == 4) 
    {
        printf("removeFirst(): PASSED\n");
    } else 
    {
        printf("removeFirst(): FAILED\n");
        testFailure = 1;
    }
    //Test destroyList()
    printList(&LL);
    printf("Destroying list...\n");
    destroyList(&LL);
    printList(&LL);
    if (LL->head == NULL && LL->tail == NULL) 
    {
        printf("destroyList(): PASSED\n");
    } else 
    {
        printf("destroyList(): FAILED\n");
        testFailure = 1;
    }
    if (testFailure == 0)
    {
        printf("ALL TESTS PASSED\n");
    } else
    {
        printf("UNIT TEST FAILURE\n");
    }
    return 0;
}