// C++ Program to find Size of Largest BST
// in a Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
          right = nullptr;
    }
};

// Returns true if the given tree is BST, else false
bool isValidBst(Node *root, int minValue, int maxValue) {
    if (!root)
        return true;
    if (root->data >= maxValue || root->data <= minValue)
        return false;
    return isValidBst(root->left, minValue, root->data) && 
           isValidBst(root->right, root->data, maxValue);
}

// Returns size of a tree
int size(Node *root) {
    if (!root)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finds the size of the largest BST
int largestBst(Node *root) {
  
    // If tree is empty
    if (!root)
        return 0;
    
    // If whole tree is BST
    if (isValidBst(root, INT_MIN, INT_MAX)) 
        return size(root);
  
    // If whole tree is not BST
    return max(largestBst(root->left), 
               largestBst(root->right));
}

int main() {
  
    // Constructed binary tree looks like this:
    //         50
    //       /    \
    //     75      45
    //    /
    //  40

    Node *root = new Node(50);
    root->left = new Node(75);
    root->right = new Node(45);
    root->left->left = new Node(40);

    cout << largestBst(root) << endl;
    return 0;
}
