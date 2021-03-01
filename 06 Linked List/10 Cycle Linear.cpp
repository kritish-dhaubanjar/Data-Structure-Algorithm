#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display(Node *p);
Node *insert(int data);
bool hasLoop(Node *head);

int main()
{
    Node *a = insert(3);
    insert(1);
    insert(5);
    insert(11);
    Node *b = insert(7);

    std::cout << "HEAD" << std::endl;
    display(head);

    std::cout << "hasLoop = " << hasLoop(head) << std::endl;

    //Loop
    b->next = a;
    // std::cout << "HEAD" << std::endl;
    // display(head);
    std::cout << "hasLoop = " << hasLoop(head) << std::endl;

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

Node *insert(int data)
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

    return node;
}

bool hasLoop(Node *p)
{
    Node *q = p;
    while (p && q)
    {
        p = p->next;
        if (q->next && q->next->next)
            q = q->next->next;
        else
            return false;

        if (p == q)
            return true;
    }

    return false;
}