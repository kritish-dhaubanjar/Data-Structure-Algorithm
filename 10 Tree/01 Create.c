#include <stdio.h>
#include <stdlib.h>
#include "01_Queue.h"

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
  if (node)
  {
    printf("%d ", node->data);
    PreOrder(node->left);
    PreOrder(node->right);
  }
}

void InOrder(Node *node)
{
  if (node)
  {
    InOrder(node->left);
    printf("%d ", node->data);
    InOrder(node->right);
  }
}

void PostOrder(Node *node)
{
  if (node)
  {
    PostOrder(node->left);
    PostOrder(node->right);
    printf("%d ", node->data);
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