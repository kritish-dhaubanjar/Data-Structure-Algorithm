#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *A = NULL;
Node *B = NULL;
Node *C = NULL;
Node *head = NULL;

void display(Node *p);
void sorted_insert(int data);
void merge(Node *A, Node *B);

int main()
{
    head = A;
    sorted_insert(2);
    sorted_insert(4);
    sorted_insert(6);
    sorted_insert(8);
    A = head;
    std::cout << "HEAD" << std::endl;
    display(A);

    head = B;
    sorted_insert(1);
    sorted_insert(3);
    sorted_insert(5);
    sorted_insert(7);
    sorted_insert(9);
    B = head;
    std::cout << "HEAD" << std::endl;
    display(B);

    merge(A, B);
    std::cout << "HEAD" << std::endl;
    display(C);
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

void merge(Node *A, Node *B)
{
    Node *a, *b, *C_TAIL = NULL;

    if (A->data < B->data)
    {
        C = C_TAIL = A;
        A = A->next;
        C->next = NULL;
    }
    else
    {
        C = C_TAIL = B;
        B = B->next;
        C->next = NULL;
    }

    while (A && B)
    {
        if (A->data < B->data)
        {
            C_TAIL->next = A;
            C_TAIL = A;
            A = A->next;
            C_TAIL->next = NULL;
        }
        else
        {
            C_TAIL->next = B;
            C_TAIL = B;
            B = B->next;
            C_TAIL->next = NULL;
        }
    }

    if (A)
        C_TAIL->next = A;
    if (B)
        C_TAIL->next = B;
}
