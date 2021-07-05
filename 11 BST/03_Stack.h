#include <stdlib.h>

typedef struct Stack
{
  int size;
  int top;
  Node **S;
} Stack;

void initStack(Stack *s, int size)
{
  s->size = size;
  s->top = -1;
  s->S = (Node **)malloc(s->size * sizeof(Node *));
}

int isStackEmpty(Stack *s)
{
  return s->top == -1;
}

int isStackFull(Stack *s)
{
  return s->top == s->size;
}

void push(Stack *s, Node *node)
{
  if (isStackFull(s))
  {
    printf("Stack is Empty");
  }
  else
  {
    s->top++;
    s->S[s->top] = node;
  }
}

Node *pop(Stack *s)
{
  Node *node = NULL;

  if (isStackFull(s))
  {
    printf("Stack is Full");
  }
  else
  {
    node = s->S[s->top];
    s->top--;
  }
  return node;
}

Node *top(Stack *s)
{
  Node *node = NULL;

  if (!isStackEmpty(s))
  {
    return s->S[s->top];
  }

  return NULL;
}