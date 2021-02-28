#include <stdio.h>
#include <stdlib.h>
#include "02_Linear_Search.h"

struct Node *head = NULL;

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create(A, 10);

    // Linear Search
    struct Node *node = linearSearch(head, 8);

    if (node)
        printf("[%p|%d|%p]\n", node, node->data, node->next);
    else
        printf("NULL\n");

    // Recursive Linear Search
    struct Node *rnode = recursiveLinearSearch(head, 5);

    if (rnode)
        printf("[%p|%d|%p]\n", rnode, rnode->data, rnode->next);
    else
        printf("NULL\n");

    // Improved Linear Search [Move to First]
    struct Node *inode = improvedLinearSearch(head, 10);

    if (inode)
        printf("[%p|%d|%p]\n", inode, inode->data, inode->next);
    else
        printf("NULL\n");

    display(head);

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

struct Node *linearSearch(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *recursiveLinearSearch(struct Node *p, int key)
{
    if (!p)
        return NULL;
    //
    if (p->data == key)
        return p;
    else
        return recursiveLinearSearch(p->next, key);
}

struct Node *improvedLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;

    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return head;
        }

        q = p;
        p = p->next;
    }

    return NULL;
}