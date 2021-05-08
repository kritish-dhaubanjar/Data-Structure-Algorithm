#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *HEAD = NULL, *TAIL = NULL;

int isEmpty()
{
    return HEAD == NULL ? 1 : 0;
}

void enqueue(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        node->data = data;
        node->next = NULL;

        if (isEmpty())
        {
            HEAD = TAIL = node;
        }
        else
        {
            TAIL->next = node;
            TAIL = node;
        }
    }
}

int dequeue()
{
    int data = -1;
    if (isEmpty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        data = HEAD->data;
        Node *temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
    }
    return data;
}

void Display()
{
    Node *p = HEAD;
    while (p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    // Display();
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    return 0;
}