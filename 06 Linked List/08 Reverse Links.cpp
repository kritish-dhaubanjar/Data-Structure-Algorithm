#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display(Node *p);
void sorted_insert(int data);
void reverse(Node *head);
void recursive_reverse(Node *node, Node *nextNode);

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
    reverse(head);
    std::cout << "HEAD" << std::endl;
    display(head);
    recursive_reverse(NULL, head);
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

void reverse(Node *HEAD)
{
    Node *p = HEAD, *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    head = q;
}

void recursive_reverse(Node *node, Node *nextNode)
{
    if (nextNode)
    {
        recursive_reverse(nextNode, nextNode->next);
        nextNode->next = node;
    }
    else
    {
        head = node;
    }
}