#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}; // *head = NULL

struct Node *head = NULL;

void create(int A[], int size)
{
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;

    struct Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void display(struct Node *p)
{
    while (p)
    {
        printf("[%p | %d | %p]\n", p, p->data, p->next);
        p = p->next;
    }
};

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    create(A, 10);

    display(head);

    return 0;
}