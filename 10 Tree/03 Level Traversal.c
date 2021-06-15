
#include <stdio.h>
#include <stdlib.h>
#include "01_Node.h"
#include "01_Queue.h"
#define SIZE 100

Node *root = NULL;

void create()
{
  Queue q;
  int size, data;

  printf("no. of Nodes:");
  scanf("%d", &size);

  init(&q, size);

  printf("root value:");
  scanf("%d", &data);

  root = (Node *)malloc(sizeof(Node));
  root->data = data;
  root->left = root->right = NULL;

  enqueue(&q, root);

  while (!isEmpty(&q))
  {
    Node *p = dequeue(&q);

    printf("left of %d: ", p->data);
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
    printf("right of %d: ", p->data);
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

void levelOrder(Node *root)
{
  Queue queue;
  init(&queue, SIZE);

  enqueue(&queue, root);

  while (!isEmpty(&queue))
  {
    Node *node = dequeue(&queue);

    printf("%d ", node->data);

    if (node->left)
    {
      enqueue(&queue, node->left);
    }

    if (node->right)
    {
      enqueue(&queue, node->right);
    }
  }
}

int main()
{
  create();
  levelOrder(root);
  return 0;
}
