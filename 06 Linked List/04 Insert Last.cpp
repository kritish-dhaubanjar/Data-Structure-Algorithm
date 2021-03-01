#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = head;

void display(Node *p);
void insert(int data);

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);
    cout << "HEAD" << endl;
    display(head);
    insert(12);
    insert(14);
    insert(16);
    insert(18);
    insert(20);
    cout << "HEAD" << endl;
    display(head);
    return 0;
}

void display(Node *p)
{
    while (p)
    {
        cout << "[" << p << "|" << p->data << "|" << p->next << "]" << endl;
        p = p->next;
    }
};

void insert(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;

    if (!head)
    {
        head = node;
        tail = head;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}