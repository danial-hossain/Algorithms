#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper function to find ceil of a given key in BST
int findCeil(Node* root, int key) {
  
    int ceil = -2; 

    while (root) {
      
        // If root itself is ceil
        if (root->data == key) {
            return root->data; 
        }
 
        // If root is smaller, the ceil
        // must be in the right subtree
        if (key > root->data) {
            root = root->right; 
        } 
      
        // Else either root can be ceil
        // or a node in the left child
        else {
            ceil = root->data; 
            root = root->left; 
        }
    }
    return ceil; 
}

// Driver code
int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    for (int i = 0; i < 16; i++)
        cout << findCeil(root, i) << "\n";

    return 0;
}
