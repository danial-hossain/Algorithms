// C++ program to find the predecessor and 
// successor of a given key in a BST
#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    Node(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Function to find the predecessor and successor
// of a given key in BST
void findPreSuc(Node* root, int key, Node*& pre, Node*& suc) {
  
    // If root is null, return
    if (!root)
        return;

    // Traverse the left subtree
    findPreSuc(root->left, key, pre, suc);

    // The first greater value seen is successor
    if (root->key > key) {        
        if (!suc || (suc && suc->key > root->key))
            suc = root;
    }
  
    // The last smaller value seen is predecessor
    else if (root->key < key)
        pre = root;

    // Traverse the right subtree
    findPreSuc(root->right, key, pre, suc);
}

int main() {
  
    int key = 65;   
  
    // Let us create the following BST
    //          50
    //       /     \
    //      30      70
    //     /  \    /  \
    //   20   40  60   80
    Node *root = new Node(50);
      root->left = new Node(30);
      root->right = new Node(70);
      root->left->left = new Node(20);
      root->left->right = new Node(40);
      root->right->right = new Node(80);
      root->right->left = new Node(60);

    Node* pre = nullptr;
    Node* suc = nullptr;

    findPreSuc(root, key, pre, suc);

    if (pre != nullptr)
        cout << "Predecessor is: " << pre->key << endl;
    else
        cout << "No Predecessor" << endl;

    if (suc != nullptr)
        cout << "Successor is: " << suc->key << endl;
    else
        cout << "No Successor" << endl;

    return 0;
}
