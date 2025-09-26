#include <stdio.h>
#include <stdlib.h>

// Define Node structures
struct Node1 {
    int data;
    struct Node1 *next;
};

struct Node2 {
    int data;
    struct Node2 *next;
};

struct Node3 {
    int data;
    struct Node3 *next;
};

// Function to print a linked list as a number in reverse order
void printLinkedListAsNumber(struct Node3 *ptr) {
    struct Node3 *temp = ptr;
    int result = 0, place = 1;

    while (temp != NULL) {
        result += (temp->data) * place;
        place *= 10;
        temp = temp->next;
    }
    printf("%d\n", result);
}

// Function to add two linked lists and create a new result list
struct Node3 *sum(struct Node1 *head1, struct Node2 *head2) {
    struct Node3 *resultHead = NULL, *currentNode = NULL, *newNode = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry;

        if (head1 != NULL) {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL) {
            sum += head2->data;
            head2 = head2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        // Create a new node for the result list
        newNode = (struct Node3 *)malloc(sizeof(struct Node3));
        newNode->data = digit;
        newNode->next = NULL;

        if (resultHead == NULL) {
            resultHead = newNode;
            currentNode = resultHead;
        } else {
            currentNode->next = newNode;
            currentNode = newNode;
        }
    }

    return resultHead;
}

int main() {
    struct Node1 *head1, *second1, *third1;
    struct Node2 *head2, *second2, *third2;

    // Allocate memory for nodes in the first linked list
    head1 = (struct Node1 *)malloc(sizeof(struct Node1));
    second1 = (struct Node1 *)malloc(sizeof(struct Node1));
    third1 = (struct Node1 *)malloc(sizeof(struct Node1));

    // Allocate memory for nodes in the second linked list
    head2 = (struct Node2 *)malloc(sizeof(struct Node2));
    second2 = (struct Node2 *)malloc(sizeof(struct Node2));
    third2 = (struct Node2 *)malloc(sizeof(struct Node2));

    // Initialize first linked list: 3 -> 4 -> 2
    head1->data = 3;
    head1->next = second1;
    second1->data = 4;
    second1->next = third1;
    third1->data = 2;
    third1->next = NULL;

    // Initialize second linked list: 4 -> 6 -> 5
    head2->data = 4;
    head2->next = second2;
    second2->data = 6;
    second2->next = third2;
    third2->data = 5;
    third2->next = NULL;

    printf("First Number: ");
    printLinkedListAsNumber((struct Node3 *)head1);

    printf("Second Number: ");
    printLinkedListAsNumber((struct Node3 *)head2);

    struct Node3 *result = sum(head1, head2);

    printf("Sum: ");
    printLinkedListAsNumber(result);

    return 0;
}
