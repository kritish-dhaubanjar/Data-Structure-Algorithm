
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

int count(Node *root)
{
  int x, y;

  if (root != NULL)
  {
    x = count(root->left);
    y = count(root->right);
    return x + y + 1;

    /*
     * Height 
     * if(root->right && root->left) return x + y + 1;
     * else return x + y;
     *
     * Sum
     * return x + y + node->data
    */
  }
  return 0;
}

int main()
{
  create();
  printf("Nodes: %d", count(root));
  return 0;
}
