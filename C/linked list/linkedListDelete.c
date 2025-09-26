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

// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return head;
}
struct Node *deleteAtLast2(struct Node *head)
{
    struct Node *p = head;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->next == NULL)
    {
        free(p);
    }

    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;

    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteAtIndexx(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
//// Case 4: Deleting the element after a given value from the linked list
struct Node *deleteAtIndexxx(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (p->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (p->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

// Case 5: Deleting the element with a given position from the linked list
struct Node *DeleteAtPos(struct Node *head, int pos)
{
    if (pos < 1)
    { // Step 1
        return NULL;
    }
    if (pos == 1)
    { // Step 2
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos; i++)
    { // Step 4
        if (curr == NULL)
        { // Out of bounds check
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    { // If position is out of bounds
        return head;
    }

    prev->next = curr->next; // Step 6: Adjust links
    free(curr);              // Step 7: Free the target node

    return head; // Step 8: Return updated head
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);
    // head = deleteAtIndexx(head, 2);
    //   head = deleteAtIndexxx(head, 3);
    //  head = deleteAtLast(head);
    // head = deleteAtLast2(head);
    head = DeleteAtPos(head, 2);
    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}