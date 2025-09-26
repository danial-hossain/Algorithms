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
struct Node *swap(struct Node *head)
{
    struct Node *p = head;
    struct Node *q=head->next;
    struct Node *r=q;
    while (p!= NULL &&  q!=NULL)
    {
        p->next=q->next;
        q->next=p;
        p=p->next->next;
        q=p->next;
    }
    return r;
}
int main()
{
    int a, b, c, d, length;
    cout << "Enter the inputs : ";
    cin >> a >> b >> c >> d;
    struct Node *head = NULL;
    head = insertEnd(head, a);
    head = insertEnd(head, b);
    head = insertEnd(head, c);
    head = insertEnd(head, d);

    cout << endl;
    cout << "Singly Linked List : ";
    cout << endl;
    printList(head);
    cout << endl;
    head=swap(head);
    printList(head);
}
