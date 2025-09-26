#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int data;
    struct ListNode *next;
};

// Function to count the number of nodes in the list
int countNodes(struct ListNode *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to sort the linked list using bubble sort
void sort(struct ListNode **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or has only one node
    }

    int n = countNodes(*head);
    struct ListNode *prev, *current, *nextNode;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = *head;

    for (int i = 0; i < n - 1; i++) {
        prev = dummy;
        current = dummy->next;
        for (int j = 0; j < n - i - 1; j++) {
            nextNode = current->next;
            if (current->data > nextNode->data) {
                // Swap nodes
                prev->next = nextNode;
                current->next = nextNode->next;
                nextNode->next = current;
                prev = nextNode;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    *head = dummy->next;
    free(dummy);
}

// Helper function to create a new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Example usage
int main() {
    // Create a sample linked list: 5 -> 3 -> 8 -> 1 -> 6 -> NULL
    struct ListNode* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(6);

    printf("Original List: ");
    printList(head);

    sort(&head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}