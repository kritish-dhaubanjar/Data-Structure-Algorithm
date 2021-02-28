#include <stdio.h>
#include <stdlib.h>
#include "01_LinkedList Basics.h"
#include <limits.h>

struct Node *head = NULL;

int main()
{
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    create(A, 10);

    display(head);

    recursiveDisplay(head);

    recursivReverseDisplay(head);

    printf("\nRecursive Count: %d\n", recursiveCount(head));

    printf("\nRecursive Sum: %d\n", recursiveSum(head));

    printf("\nMax: %d\n", max(head));

    return 0;
}

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

void recursiveDisplay(struct Node *p)
{
    if (p)
    {
        printf("[%p | %d | %p]\n", p, p->data, p->next);
        recursiveDisplay(p->next);
    }
};

void recursivReverseDisplay(struct Node *p)
{
    if (p)
    {
        recursivReverseDisplay(p->next);
        printf("[%p | %d | %p]\n", p, p->data, p->next);
    }
};

int recursiveCount(struct Node *p)
{
    if (p)
        return 1 + recursiveCount(p->next);
    return 0;
}

int recursiveSum(struct Node *p)
{
    if (p)
        return p->data + recursiveSum(p->next);
    return 0;
}

int max(struct Node *p)
{
    if (!p)
        return INT_MIN;
    int t = max(p->next);
    return p->data > t ? p->data : t;
}
