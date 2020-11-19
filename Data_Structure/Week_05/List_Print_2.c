#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *link;
} ListNode;

void printList(ListNode *h)
{
    while (h != NULL) {
        printf("%d ", h->data);
        h = h->link;
    }
    printf("\n");
}

int main()
{
    ListNode    *p1, *p2, *p3;
    p1 = (ListNode *) malloc(sizeof(ListNode));
    p2 = (ListNode *) malloc(sizeof(ListNode));
    p3 = (ListNode *) malloc(sizeof(ListNode));
    p1 -> data =15;
    p1 -> link=p2; 
    p2 -> link=p3;
    p3 -> link=NULL;

    printList(p1);
    free(p2);
    free(p3);
}
