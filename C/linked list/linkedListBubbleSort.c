#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void printing(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *reversing(struct Node *head)
{
    struct Node * ptr=head;
    struct Node * next=NULL;
    struct Node * prev=NULL;
    while(ptr!=NULL)
    {
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    return prev;
}
struct Node *insFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}
struct Node *insLast(struct Node *head, int data)
{
    struct Node *ptr;
    struct Node *p = head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (head == NULL)
    {
        return ptr;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
void bubbleSort(struct Node *head, int size)
{
    struct Node *p;
    struct Node *q;
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        p=head;
        q=head->next;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (p->data < q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        
        p = q;
        q = q->next;
        }
    }
}
int main()
{
    struct Node *head = NULL;
    head = insFirst(head, 10);
    head = insLast(head, 20);
    head = insLast(head, 30);
    head = insLast(head, 40);
    printf("Before Reversing : ");
    printing(head);
    printf("\n");
    printf("After Reversing : ");
    //bubbleSort(head, 4);
    head=reversing(head);
    printing(head);
}