#include <iostream>

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

Node *head = NULL;

Node *insert(int data);
void display(Node *head);

int main()
{
    insert(3);
    Node *H = insert(1);
    insert(7);
    insert(5);
    Node *T = insert(11);

    H->prev = T;
    T->next = H;

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
        if (p == head)
            break;
    }
}

Node *insert(int data)
{
    Node *node = new Node;
    node->data = data;
    node->prev = node->next = NULL;

    Node *p = head, *q;
    while (p && p->data < data && p->next && p->next->data < data)
    {
        p = p->next;
    }

    if (p == head)
    {
        node->next = p;
        head = node;
        if (p)
            p->prev = head;
    }
    else
    {

        if (!p->next)
        {
            p->next = node;
            node->prev = p;
        }
        else
        {
            node->prev = p;
            node->next = p->next;

            p->next = node;
            p->next->prev = node;
        }
    }

    return node;
}