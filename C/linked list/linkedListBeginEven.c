#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *exchangeEvenOddList(struct ListNode *head) {
    // Initialize the odd and even list headers
    struct ListNode *oddList = NULL, *evenList = NULL;
    // Create tail variables for both lists
    struct ListNode *oddListEnd = NULL, *evenListEnd = NULL;
    struct ListNode *itr = head;

    if (head == NULL) {
        return NULL; // Return NULL if the list is empty
    }

    while (itr != NULL) {
        if (itr->data % 2 == 0) { // Even node
            if (evenList == NULL) {
                // First even node
                evenList = evenListEnd = itr;
            } else {
                // Insert the node at the end of the even list
                evenListEnd->next = itr;
                evenListEnd = itr;
            }
        } else { // Odd node
            if (oddList == NULL) {
                // First odd node
                oddList = oddListEnd = itr;
            } else {
                // Insert the node at the end of the odd list
                oddListEnd->next = itr;
                oddListEnd = itr;
            }
        }
        itr = itr->next;
    }

    // Connect the even list to the odd list
    if (evenListEnd != NULL) {
        evenListEnd->next = oddList;
    } else {
        evenList = oddList; // If no even nodes, return the odd list
    }

    // Ensure the last node's next pointer is NULL
    if (oddListEnd != NULL) {
        oddListEnd->next = NULL;
    }

    return evenList; // Return the head of the modified list
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
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printList(head);

    head = exchangeEvenOddList(head);

    printf("Modified List: ");
    printList(head);

    return 0;
}