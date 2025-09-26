#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// Create a new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node *insert(Node *root, int target)
{
    if (!root)
        return createNode(target);

    if (target < root->data)
        root->left = insert(root->left, target);
    else
        root->right = insert(root->right, target);

    return root;
}

// Inorder Traversal
void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int level(Node *root, int level)
{
    if (!root)
        return 0;
    if (root->left && root->right == NULL)
        return level;
    level(root->left, level);
    level++;
    level(root->right, level);
}
// Search in BST
bool search(Node *root, int target)
{
    if (!root)
        return false;

    if (root->data == target)
        return true;
    else if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

Node *deleteNode(Node *root, int target)
{
    // your code goes here

    // base condition
    if (!root)
        return NULL;

    if (root->data > target)
    {
        root->left = deleteNode(root->left, target);
        return root;
    }
    else if (root->data < target)
    {
        root->right = deleteNode(root->right, target);
        return root;
    }
    else
    {
        // Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // 1 child exist
        else if (!root->right)
        { // left child exist
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (!root->left)
        { // right child exist
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child exist
        else
        {
            // find the greatest element from left
            Node *child = root->left;
            Node *parent = root;

            // Right most node tak pauchna hai
            while (child->right)
            {
                parent = child;
                child = child->right;
            }

            if (root != parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            else
            {
                child->right = root->right;
                delete root;
                return child;
            }
        }
    }
}

int main()
{
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node *root = NULL;

    for (int i = 0; i < 10; i++)
        root = insert(root, arr[i]);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    int target = 11;
    if (search(root, target))
        cout << "Found " << target << " in the tree." << endl;
    else
        cout << target << " not found in the tree." << endl;

    return 0;
}
