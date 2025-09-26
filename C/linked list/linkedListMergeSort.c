#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *merged = NULL;
void printing(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
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
        ptr->next = NULL;
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
void merge(struct Node *first, struct Node *second)
{

    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            merged = insLast(merged, first->data);
            first = first->next;
        }
        else
        {
            merged = insLast(merged, second->data);
            second = second->next;
        }
    }
    while (first != NULL)
    {
        merged = insLast(merged, first->data);
        first = first->next;
    }
    while (second != NULL)
    {
        merged = insLast(merged, second->data);
        second = second->next;
    }
}

int main()
{
    struct Node *head1 = NULL;

    head1 = insFirst(head1, 10);
    head1 = insLast(head1, 20);
    head1 = insLast(head1, 40);

    struct Node *head2 = NULL;

    head2 = insFirst(head2, 10);
    head2 = insLast(head2, 30);
    head2 = insLast(head2, 40);

    printf("First Linked List : ");
    printing(head1);
    printf("\n");
    printf("Second Linked List : ");
    printing(head2);
    printf("\n");
    printf("After Merging : ");
    merge(head1, head2);
    printing(merged);
}