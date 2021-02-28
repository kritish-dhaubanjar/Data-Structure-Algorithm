#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void create(int A[], int size);
void display(Node *p);
void insert(Node *p, int pos, int data);

int main()
{
    int A[] = {2, 4, 6, 8, 10};

    create(A, 5);
    display(head);
    insert(head, 0, -1);
    insert(head, 4, -4);
    insert(head, 8, -8);
    cout << endl;
    display(head);

    return 0;
}

void create(int A[], int size)
{
    head = new Node;
    head->data = A[0];
    head->next = NULL;

    Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << "[" << p << "|" << p->data << "|" << p->next << "]" << endl;
        p = p->next;
    }
};

void insert(Node *p, int pos, int data)
{
    if (pos == 0)
    {
        Node *t = new Node;
        t->data = data;
        t->next = head;
        head = t;
    }
    else if (p > 0)
    {
        for (int i = 0; i < pos - 1 && p; i++)
            p = p->next;

        if (p)
        {
            Node *t = new Node;
            t->data = data;
            t->next = p->next;
            p->next = t;
        }
        return;
    }
}