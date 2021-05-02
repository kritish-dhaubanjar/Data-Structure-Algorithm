#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node)
    {
        node->data = data;
        node->next = top;
        top = node;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop()
{
    if (top)
    {
        Node *node = top;
        top = top->next;

        int el = node->data;
        free(node);
        return el;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int peek(int pos)
{
    Node *tmp = top;
    for (int i = 0; tmp != NULL && i < pos - 1; i++)
    {
        tmp = tmp->next;
    }

    return tmp->data;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    printf("Peek @ %d = %d\n", 3, peek(3));

    for (int i = 0; i < 11; i++)
    {
        printf("%d\n", pop());
    }
    return 0;
}
