#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int rear;
    int front;
    int *Q;
} Queue;

void init(Queue *queue, int size)
{
    queue->size = size;
    queue->Q = (int *)malloc(size * sizeof(int));
    queue->rear = -1;
    queue->front = -1;
}

int isEmpty(Queue *queue)
{
    return (queue->rear == queue->front);
}

int isFull(Queue *queue)
{
    return (queue->rear == queue->size - 1);
}

void enqueue(Queue *queue, int data)
{
    if (!isFull(queue))
    {
        queue->Q[++queue->rear] = data;
    }
    else
    {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue)
{
    if (!isEmpty(queue))
    {
        return queue->Q[++queue->front];
    }
    else
    {
        printf("Queue underflow\n");
        return -1;
    }
}

int main()
{
    Queue queue;

    init(&queue, 10);

    for (int i = 0; i < 5; i++)
    {
        enqueue(&queue, i);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", dequeue(&queue));
    }

    for (int i = 0; i < 15; i++)
    {
        enqueue(&queue, i);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", dequeue(&queue));
    }

    return 0;
}