// C++ Program to find kth largest element
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node (int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

// Function which will traverse the BST
// in reverse inorder manner.
int kthLargestRecur(Node* root, int &cnt, int k) {

    // base case
    if (root == nullptr)
        return -1;
        
    int right = kthLargestRecur(root->right, cnt, k);
    
    // if kth largest number is present in
    // right subtree, then return it.
    if (right != -1)
        return right;
    
    // Increment the node count.
    cnt++;
    
    // If root node is the kth largest element,
    // then return it.
    if (cnt == k) 
        return root->data;
        
    int left = kthLargestRecur(root->left, cnt, k);
    
    // else return value provided by
    // left subtree.
    return left;
}

int kthLargest(Node* root, int k) {
    int cnt = 0;
    return kthLargestRecur(root, cnt, k);
}

int main() {
    
    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \  
    //   4   12  
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    int k = 3;
    
    cout << kthLargest(root, k) << endl;
    
    return 0;
}
