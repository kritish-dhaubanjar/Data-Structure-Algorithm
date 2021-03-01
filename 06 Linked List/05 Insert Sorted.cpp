#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

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
    insert(1);
    insert(3);
    insert(5);
    insert(7);
    insert(9);
    insert(11);
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
    }
    else
    {
        Node *p = head, *q = NULL;
        while (p && p->data < data)
        {
            q = p;
            p = p->next;
        }

        /*
        if (!p)
        {
            q->next = node;
        }
        else
        {
            if (p == head)
            {
                node->next = head;
                head = node;
            }
            else
            {
                node->next = p;
                q->next = node;
            }
        }
    */

        if (p == head)
        {
            node->next = head;
            head = node;
        }
        else
        {
            node->next = q->next;
            q->next = node;
        }
    }
}