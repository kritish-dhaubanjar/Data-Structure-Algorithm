#include <stdio.h>
#include "03_Node.h"
#include "03_Stack.h"

Node *root = NULL;
Stack stack;

Node *newNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void createBST(int preorder[], int n)
{
  int i = 0;
  Node *p, *t;

  p = newNode(preorder[i++]);
  root = p;

  while (i < n)
  {
    if (preorder[i] < p->data)
    {
      t = newNode(preorder[i++]);
      p->left = t;
    }
    else
    {
      if (preorder[i] > p->data && (isStackEmpty(&stack) || preorder[i] < top(&stack)->data))
      {
        t = newNode(preorder[i++]);
        p->right = t;
        p = t;
      }
      else
      {
        p = pop(&stack);
      }
    }
  }
}

void inorder(Node *node)
{
  if (node)
  {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

int main()
{
  int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
  int n = 8;
  initStack(&stack, n);

  createBST(preorder, n);

  inorder(root);

  return 0;
}