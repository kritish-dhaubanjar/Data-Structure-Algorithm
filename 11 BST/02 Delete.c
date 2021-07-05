#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *left;
  int data;
  struct Node *right;
} Node;

Node *root = NULL;

void insert(int key)
{
  Node *p;
  Node *t = root, *r = NULL;

  p = (Node *)malloc(sizeof(Node));
  p->data = key;
  p->left = p->right = NULL;

  if (root == NULL)
  {

    root = p;
    return;
  }

  while (t != NULL)
  {
    r = t;
    if (key < t->data)
      t = t->left;
    else if (key > t->data)
      t = t->right;
    else
      return;
  }

  if (key < r->data)
    r->left = p;
  else
    r->right = p;
}

void inorder(Node *p)
{
  if (p)
  {
    inorder(p->left);
    printf("%d ", p->data);
    inorder(p->right);
  }
}

int height(Node *p)
{
  int x, y;
  if (p == NULL)
    return 0;
  x = height(p->left);
  y = height(p->right);
  return x > y ? x + 1 : y + 1;
}

Node *InOrderPredecessor(Node *p)
{
  while (p && p->right != NULL)
    p = p->right;
  return p;
}
Node *InOrderSuccessor(Node *p)
{
  while (p && p->left != NULL)
    p = p->left;
  return p;
}

Node *delete (Node *p, int key)
{
  Node *q;
  if (p == NULL)
    return NULL;

  if (p->left == NULL && p->right == NULL)
  {
    if (p == root)
      root = NULL;
    free(p);
    return NULL;
  }

  if (key < p->data)
    p->left = delete (p->left, key);
  else if (key > p->data)
    p->right = delete (p->right, key);
  else
  {
    if (height(p->left) > height(p->right))
    {
      q = InOrderPredecessor(p->left);
      p->data = q->data;
      p->left = delete (p->left, q->data);
    }
    else
    {
      q = InOrderSuccessor(p->right);
      p->data = q->data;
      p->right = delete (p->right, q->data);
    }
  }
  return p;
}

int main()
{
  insert(50);
  insert(10);
  insert(40);
  insert(20);
  insert(30);

  inorder(root);

  delete (root, 40);

  inorder(root);
  return 0;
}