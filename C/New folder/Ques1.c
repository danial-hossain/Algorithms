#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* modify(struct Node *ptr, int k)
{
    struct Node *p = ptr;
    struct Node *q = ptr;
       struct Node *r; 
    for (int i = 0; i < 5 - k-1; i++)
    {
        p = p->next;
    }
    r=p;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = ptr;
    ptr = p->next;

    r->next= NULL;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = fifth;

    fifth->data = 9;
    fifth->next = NULL;

    linkedListTraversal(head);
   head= modify(head, 3);
    printf("\n \n");
    linkedListTraversal(head);
    return 0;
}
