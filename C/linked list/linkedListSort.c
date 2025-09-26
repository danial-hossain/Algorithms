#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to perform bubble sort on the linked list
void bubbleSort(struct Node *head, int size) {
    struct Node *p;
    struct Node *q;
    int temp;

    for (int i = 0; i < size - 1; i++) {
        p = head;
        q = head->next;

        for (int j = 0; j < size - i - 1; j++) {
            if (p->data > q->data) {
                // Swap the data of the nodes
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            // Move to the next pair of nodes
            p = q;
            q = q->next;
        }
    }
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Initialize linked list
    head->data = 5;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    // Before sorting
    printf("Before Sorting:\n");
    linkedListTraversal(head);

    // Perform bubble sort
    bubbleSort(head, 4);

    // After sorting
    printf("\nAfter Sorting:\n");
    linkedListTraversal(head);

    // Free allocated memory
    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}
