
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
struct Node *insertBegin(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
struct Node *insertEnd(struct Node *head, int data)
{

    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        return ptr;
    }
    struct Node *p = head;
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        return head;
    }
}
void middle(struct Node *head)
{

    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}
int mid(struct Node *head)
{
    int size = 0;
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    ptr = head;
    int i = 0;
    {

        while (i < ((size / 2) + 1 - 1))
        {
            ptr = ptr->next;
            i++;
        }
    }

    cout << ptr->data;
}
int main()
{
    int a, b, c, d, e, f, g, length;
    cout << "Enter the inputs : ";
    cin >> a >> b >> c >> d >> e >> f >> g;
    struct Node *head = NULL;
    head = insertEnd(head, a);
    head = insertEnd(head, b);
    head = insertEnd(head, c);
    head = insertEnd(head, d);
    head = insertEnd(head, e);
    head = insertEnd(head, f);
    head = insertEnd(head, g);

    cout << endl;
    cout << "Singly Linked List : ";
    cout << endl;
    printList(head);
    // cout<<"Middle : ";
    // middle(head);
    mid(head);
}
