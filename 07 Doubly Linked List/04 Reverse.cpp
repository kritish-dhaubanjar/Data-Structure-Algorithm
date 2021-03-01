#include <iostream>

struct Node
{
    int data;
    Node *prev, *next;
};

Node *head = NULL;

void create(int A[], Node *head);
void display(Node *head);
void reverse(Node *head);

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    create(A, head);
    reverse(head);
    std::cout << "HEAD" << std::endl;
    display(head);
    return 0;
}

void display(Node *p)
{
    while (p)
    {
        std::cout << "[" << p->prev << "|" << p->data << "|" << p << "|" << p->next << "]" << std::endl;
        p = p->next;
    }
}

void create(int A[], Node *p)
{
    Node *node = new Node;
    node->data = A[0];
    node->next = node->prev = NULL;

    head = node;

    Node *tail = head;

    for (int i = 1; i < 5; i++)
    {
        Node *node = new Node;
        node->data = A[i];
        node->next = NULL;
        node->prev = tail;

        tail->next = node;

        tail = node;
    }
}

void reverse(Node *p)
{
    while (p)
    {
        if (!p->next)
        {
            head = p;
        }
        Node *tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = p->prev;
    }
}