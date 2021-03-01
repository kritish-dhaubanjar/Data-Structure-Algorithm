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
void destroy(int index);

int main()
{
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    insert(10);
    cout << "HEAD" << endl;
    display(head);
    destroy(0);
    cout << "HEAD" << endl;
    display(head);
    destroy(2);
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

void destroy(int index)
{
    Node *q, *p = head;

    if (index == 0)
    {
        p = head;

        if (!head->next)
        {
            head = NULL;
            tail = head;
        }
        else
        {
            head = head->next;
        }
        delete p;
    }
    else
    {
        for (int i = 0; i < index && p; i++)
        {
            q = p;
            p = p->next;
        }

        if (p)
        {
            q->next = p->next;
        }
        delete p;
    }
}