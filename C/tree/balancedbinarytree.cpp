// C++ program to check if a tree is height-balanced or not 
// Using Top Down Recursion

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        int data = d;
        left = right = NULL;
    }
};

// Function to calculate the height of a tree
int height(Node* node) {
  
    // Base case: Height of empty tree is zero
    if (node == NULL)
        return 0;

    // Height = 1 + max of left height and right heights
    return 1 + max(height(node->left), height(node->right));
}

// Function to check if the binary tree with given root, is height-balanced
bool isBalanced(Node* root) {

    // If tree is empty then return true
    if (root == NULL)
        return true;

    // Get the height of left and right sub trees
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
      // If absolute height difference is greater than 1
      // Then return false
    if (abs(lHeight - rHeight) > 1)
        return false;

    // Recursively check the left and right subtrees
    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    // Representation of input BST:
    //            1
    //           / \
    //          2   3
    //         /  \
    //        4   5 
    //       /
    //      8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    cout << (isBalanced(root) ? "True" : "False");
    return 0;
}
