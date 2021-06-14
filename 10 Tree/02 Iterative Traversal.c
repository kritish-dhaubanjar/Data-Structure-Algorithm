#include <stdio.h>
#include <stdlib.h>
#include "01_Node.h"
#include "01_Queue.h"
#include "01_Stack.h"
#define SIZE 100

Node *root = NULL;

void create()
{
  Queue q;
  int size, data;

  printf("No. of Nodes:");
  scanf("%d", &size);

  init(&q, size);

  printf("Root Value:");
  scanf("%d", &data);

  root = (Node *)malloc(sizeof(Node));
  root->data = data;
  root->left = root->right = NULL;

  enqueue(&q, root);

  while (!isEmpty(&q))
  {
    Node *p = dequeue(&q);

    printf("Left of %d: ", p->data);
    scanf("%d", &data);

    if (data != -1)
    {
      Node *t = (Node *)malloc(sizeof(Node));
      t->data = data;
      t->left = t->right = NULL;
      p->left = t;
      enqueue(&q, t);
    }
    //
    printf("Right of %d: ", p->data);
    scanf("%d", &data);

    if (data != -1)
    {
      Node *t = (Node *)malloc(sizeof(Node));
      t->data = data;
      t->left = t->right = NULL;
      p->right = t;
      enqueue(&q, t);
    }
  }
}

void PreOrder(Node *node)
{
  Stack stack;

  initStack(&stack, SIZE);

  while (node != NULL || !isStackEmpty(&stack))
  {
    if (node != NULL)
    {
      printf("%d ", node->data);
      push(&stack, node);
      node = node->left;
    }
    else
    {
      node = pop(&stack);
      node = node->right;
    }
  }
}

void InOrder(Node *node)
{
  Stack stack;

  initStack(&stack, SIZE);

  while (node != NULL || !isStackEmpty(&stack))
  {
    if (node != NULL)
    {
      push(&stack, node);
      node = node->left;
    }
    else
    {
      node = pop(&stack);
      printf("%d ", node->data);
      node = node->right;
    }
  }
}

void PostOrder(Node *node)
{
  Stack stack;

  initStack(&stack, SIZE);

  while (node != NULL || !isStackEmpty(&stack))
  {
    if (node != NULL)
    {
      push(&stack, node);
      node = node->left;
    }
    else
    {
      node = pop(&stack);

      if (node->data > 0)
      {
        node->data *= -1;
        push(&stack, node);
        node = node->right;
      }
      else
      {
        printf("%d ", node->data * -1);
        node = NULL;
      }
    }
  }
}

int main()
{
  create();
  PreOrder(root);
  printf("\n");
  InOrder(root);
  printf("\n");
  PostOrder(root);
  return 0;
}