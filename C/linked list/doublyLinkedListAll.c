#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversalStarting(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void linkedListTraversalEnding(struct Node *tail)
{
    struct Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head->prev = ptr;
        ptr->prev = NULL;
        head = ptr;
    }
    return head;
}
struct Node *insertAtLast(struct Node *tail, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (tail == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        tail = ptr;
    }
    else
    {
        tail->next = ptr;
        ptr->prev = tail;
        ptr->next = NULL;
        tail = ptr;
    }
    return tail;
}
struct Node *insertAtPos(struct Node *head, struct Node **tail, int data, int pos)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    struct Node *ptr = head;
    struct Node *size = head;
    int q = 0;
    while (size != NULL)
    {
        q++;
        size = size->next;
    }
    if (pos == q + 1)
    {
        *tail = insertAtLast(*tail, data);
        return head;
    }
    if (pos == 1)
    {
        head = insertAtFirst(head, data);
        return head;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    p->next = ptr;
    p->prev = ptr->prev;
    ptr->prev->next = p;
    ptr->prev = p;

    return head;
}
struct Node *insertBeforeValue(struct Node *head, struct Node **tail, int data, int pos)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    struct Node *ptr = head;
    struct Node *size = head;
    int q = 0;
    while (size != NULL)
    {
        q++;
        size = size->next;
    }
    if (pos == q + 1)
    {
        *tail = insertAtLast(*tail, data);
        return head;
    }
    if (pos == 1)
    {
        head = insertAtFirst(head, data);
        return head;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    p->next = ptr;
    p->prev = ptr->prev;
    ptr->prev->next = p;
    ptr->prev = p;

    return head;
}
struct Node *insertAfterValue(struct Node *head, struct Node **tail, int data, int pos)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    struct Node *ptr = head;
    struct Node *size = head;
    int q = 0;
    while (size != NULL)
    {
        q++;
        size = size->next;
    }
    if (pos == q + 1)
    {
        *tail = insertAtLast(*tail, data);
        return head;
    }
    if (pos == 1)
    {
        head = insertAtFirst(head, data);
        return head;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    p->next = ptr;
    p->prev = ptr->prev;
    ptr->prev->next = p;
    ptr->prev = p;

    return head;
}




struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL)
    {
        printf("Lindked List is Emptry");
        return head;
    }
    else
    {
        struct Node *ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
    }
}
struct Node *deleteAtLast(struct Node *tail)
{

    struct Node *ptr = tail;
    ptr->prev->next = NULL;
    tail = ptr->prev;
    free(ptr);
    return tail;
}
struct Node *deleteAtPos(struct Node *head, struct Node **tail, int pos)
{
    struct Node *ptr = head;
    struct Node *size = head;
    int q = 0;
    if (pos == 1)
    {
        ptr = deleteAtFirst(ptr);
        return ptr;
    }
    while (size != NULL)
    {
        q++;
        size = size->next;
    }
    if (pos == q)
    {
        *tail = deleteAtLast(*tail);
        return head;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        if (ptr != NULL)
        {
            ptr = ptr->next;
        }
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}
struct Node *deleteAtValue(struct Node *head, struct Node **tail, int val)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            break;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Item Not found");
        return head;
    }
    if (ptr->prev == NULL)
    {
        ptr = deleteAtFirst(ptr);
        return ptr;
    }
    if (ptr->next == NULL)
    {
        *tail = deleteAtLast(*tail);
        return head;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    return head;
}
void printingF(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void printingB(struct Node *tail)
{
    struct Node *ptr = tail;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}
void searching(struct Node *head, int val)
{
    struct Node *ptr = head;
    int i = 1;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            break;
        }
        i++;
        ptr=ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Item not found");
    }
    else
    {
        printf("Item found at position %d", i);
    }
}
void last_node(struct Node *tail)
{
    struct Node *ptr = tail;
    printf("%d", tail->data);
}
void previous_of_last_node(struct Node *tail)
{
    struct Node *ptr = tail;
    printf("%d", tail->prev->data);
}
void list_size(struct Node *head)
{
    struct Node *ptr = head;
    int p = 0;
    while (ptr != NULL)
    {
        p++;
        ptr = ptr->next;
    }
    printf("Size of the linked list %d", p);
}
struct Node *connect(struct Node *tail)
{
    struct Node *ptr = tail;
    while (ptr->prev != NULL)
    {
        ptr = ptr->prev;
    }
    return ptr;
}
int main()
{

    struct Node *head = NULL;
    struct Node *tail = NULL;

    tail = insertAtLast(tail, 3);
    tail = insertAtLast(tail, 9);
    tail = insertAtLast(tail, 6);
    tail = insertAtLast(tail, 13);
    head = connect(tail);

    printf("Before inserting : ");
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After inserting at first : ");
    head = insertAtFirst(head, 1);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After inserting at last : ");
    tail = insertAtLast(tail, 17);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After inserting 19 at  a given position 7 : ");
    head = insertAtPos(head, &tail, 19, 7);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After deleting first element : ");
    head = deleteAtFirst(head);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After deleting last element : ");
    tail = deleteAtLast(tail);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After deleting at a given position 5 : ");
    head = deleteAtPos(head, &tail, 5);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("After deleting at a given value : ");
    head = deleteAtValue(head, &tail, 13);
    linkedListTraversalStarting(head);
    printf("\n");
    printf("Printing on forward : ");
    printingF(head);
    printf("\n");
    printf("Printing on reverse : ");
    printingB(tail);
    printf("\n \n");
    printf("Searching  element 6 : ");
    searching(head,6);
    printf("\n \n");
    printf("Printing last node : ");
    last_node(tail);
    printf("\n \n");
    printf("Printing previous of last node : ");
    previous_of_last_node(tail);
    printf("\n \n");
    list_size(head);
    return 0;
}