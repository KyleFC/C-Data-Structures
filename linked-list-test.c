#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.c"

int main() 
{
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
    }
    //Test findNode()
    node *foundNode = findNode(&LL, 2);
    printf("%d\n", foundNode->data);
    //Test unlinkNode
    unlinkNode(&LL, 2);
    if (findNode(&LL, 2) == NULL) 
    {
        printf("unlinkNode(): PASSED\n");
    } else 
    {
        printf("unlinkNode(): FAILED\n");
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
    }
    //Test destroyList()
    destroyList(&LL);
    if (LL->head == NULL && LL->tail == NULL) 
    {
        printf("destroyList(): PASSED\n");
    } else 
    {
        printf("destroyList(): FAILED\n");
    }
    return 0;
}