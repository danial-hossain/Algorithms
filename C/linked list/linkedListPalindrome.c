#include <stdio.h>
#include <stdlib.h>

// Definition of ListNode
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

// Function to check if linked list is palindrome
int isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return 1;  // Empty or single-node list is always a palindrome

    // Step 1: Find the middle of the list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half
    struct ListNode* secondHalf = reverseList(slow->next);
    struct ListNode* firstHalf = head;
    struct ListNode* temp = secondHalf;

    // Step 3: Compare both halves
    while (temp != NULL) {
        if (firstHalf->val != temp->val) {
            reverseList(secondHalf);  // Restore original list before returning
            return 0;  // Not a palindrome
        }
        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    // Step 4: Restore the original list
    slow->next = reverseList(secondHalf);
    
    return 1;  // Palindrome
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Test the function
int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is NOT a palindrome.\n");

    return 0;
}
