#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
   int data;
   struct ListNode* link;
}ListNode;

void display(ListNode* h)
{
   while (h != NULL) 
   {
      printf("%d ", h->data);
      h = h->link;
   }
   printf("\n");
}

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
   if (*phead == NULL)
   {
      new_node->link = NULL;
      *phead = new_node;
   }
   else if (p == NULL)
   {
      p = *phead;
      while (p->link)
         p = p->link;
      p->link = new_node;
   }
   else
   {
      new_node->link = p->link;
      p->link = new_node;
   }
}

int main()
{
   ListNode* head = NULL;
   ListNode* p, * new_node;
   int data;

   p = head;
   do 
   {
      scanf("%d", &data);
      if (data == -1)
         break;

      new_node = (ListNode*)malloc(sizeof(ListNode));
      new_node->data = data;
      new_node->link = NULL;

      insert_node(&head, p, new_node);
   } 
   while (1);

   display(head);
}
