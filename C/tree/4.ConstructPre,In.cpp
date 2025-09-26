#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int find(int in[], int target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == target)
            return i;
    }
    return -1;
}

Node* Tree(int in[], int pre[], int InStart, int InEnd, int index) {
    if (InStart > InEnd)
        return NULL;

    Node* root = new Node(pre[index]);
    int pos = find(in, pre[index], InStart, InEnd);

    // Left subtree
    root->left = Tree(in, pre, InStart, pos - 1, index + 1);

    // Right subtree
    root->right = Tree(in, pre, pos + 1, InEnd, index + (pos - InStart) + 1);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    return Tree(in, pre, 0, n - 1, 0);
}
void inorderPrint(Node* root) {
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in) / sizeof(in[0]);

    Node* root = buildTree(in, pre, n);

    cout << "Inorder traversal of the constructed tree: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}