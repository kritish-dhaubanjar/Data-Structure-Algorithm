#include <stdlib.h>

typedef struct Queue
{
  int size;
  int front;
  int rear;
  Node **Q;
} Queue;

int isEmpty(Queue *q)
{
  return q->front == q->rear;
}

int isFull(Queue *q)
{
  return q->rear == q->size - 1;
}

void enqueue(Queue *q, Node *node)
{
  if (isFull(q))
  {
    printf("Queue is Full");
  }
  else
  {
    q->rear++;
    q->Q[q->rear] = node;
  }
}

Node *dequeue(Queue *q)
{
  Node *node = NULL;

  if (isEmpty(q))
  {
    printf("Queue is Empty");
  }
  else
  {
    q->front++;
    node = q->Q[q->front];
  }

  return node;
}

void init(Queue *q, int size)
{
  q->Q = (Node **)malloc(size * sizeof(Node *));
  q->size = size;
  q->front = -1;
  q->rear = -1;
}
