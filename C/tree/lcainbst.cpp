// C++ program to find LCA of given node in BST
// Using Properties of BST and Recursion

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find LCA of nodes n1 and n2, assuming
// both are present in the BST
Node* LCA(Node* root, Node* n1, Node* n2) {
      
    if (root == nullptr)
        return nullptr;

    // If both n1 and n2 are smaller than 
    // root, go to left subtree
    if (root->data > n1->data && root->data > n2->data)
        return LCA(root->left, n1, n2);

    // If both n1 and n2 are greater than 
    // root, go to right subtree
    if (root->data < n1->data && root->data < n2->data)
        return LCA(root->right, n1, n2);

    // If nodes n1 and n2 are on the opposite sides, 
    // then root is the LCA
    return root;
}

int main() {
      
      // Representation of input BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14  
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Node* n1 = root->left->left; // Node 4
    Node* n2 = root->left->right->right; // Node 14

    Node* res = LCA(root, n1, n2);
    cout << res->data << endl;

    return 0;
}

