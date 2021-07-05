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

int search(int key)
{
  Node *t = root;

  while (t != NULL)
  {

    if (t->data == key)
      return t->data;
    else if (key < t->data)
      t = t->left;
    else
      t = t->right;
  }

  return -1;
}

int main()
{
  insert(50);
  insert(10);
  insert(40);
  insert(20);
  insert(30);

  printf("%d\n", search(40));

  inorder(root);
  return 0;
}