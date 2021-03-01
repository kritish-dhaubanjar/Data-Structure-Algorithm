#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display(Node *p);
void sorted_insert(int data);
void remove_duplicates(Node *head);

int main()
{
    sorted_insert(1);
    sorted_insert(4);
    sorted_insert(3);
    sorted_insert(5);
    sorted_insert(2);
    sorted_insert(0);
    sorted_insert(1);
    sorted_insert(4);
    sorted_insert(3);
    sorted_insert(5);
    std::cout << "HEAD" << std::endl;
    display(head);
    remove_duplicates(head);
    std::cout << "HEAD" << std::endl;
    display(head);
    return 0;
}

void display(Node *p)
{
    while (p)
    {
        std::cout << "[" << p << "|" << p->data << "|" << p->next << "]" << std::endl;
        p = p->next;
    }
}

void sorted_insert(int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;

    Node *p = head, *q = NULL;

    while (p && p->data < data)
    {
        q = p;
        p = p->next;
    }

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

void remove_duplicates(Node *head)
{
    Node *p = head;
    Node *q = NULL;

    if (!p->next)
        return;

    q = p->next;

    while (p && q)
    {

        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}