#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to find and print the middle node of the linked list
void findMiddleNode(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *slow = head;  // Slow pointer moves one step at a time
    struct Node *fast = head; // Fast pointer moves two steps at a time

    // Traverse the list
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // When the loop ends, slow pointer will be at the middle node
    printf("The middle node is: %d\n", slow->data);
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

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 66;
    fourth->next = NULL;

    // Traverse and print the linked list
    printf("Linked List:\n");
    linkedListTraversal(head);

    // Find and print the middle node
    findMiddleNode(head);

    return 0;
}
