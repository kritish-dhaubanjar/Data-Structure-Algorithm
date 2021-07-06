#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  struct Node *next;
  int data;
} Node;

Node *sortedInsert(Node **node, int key)
{
  Node *t = (Node *)malloc(sizeof(Node));
  t->data = key;
  t->next = NULL;

  if (*node == NULL)
  {
    *node = t;
  }
  else
  {
    Node *head = *node;
    Node *tail = NULL;

    while (head != NULL && head->data < key)
    {
      tail = head;
      head = head->next;
    }

    if (head == *node)
    {
      t->next = head;
      *node = t;
    }
    else
    {
      t->next = tail->next;
      tail->next = t;
    }
  }
}

void display(Node *H[])
{
  for (int i = 0; i < 10; i++)
  {
    printf("[%d]", i);

    Node *node = H[i];

    while (node != NULL)
    {
      printf("->[%d]", node->data);
      node = node->next;
    }

    printf("\n");
  }
}

int hash(int key)
{
  return key % 10;
}

int main()
{
  Node *H[10];
  int keys[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};

  for (int i = 0; i < 10; i++)
    H[i] = NULL;

  for (int i = 0; i < 9; i++)
  {
    sortedInsert(&H[hash(keys[i])], keys[i]);
  }

  display(H);

  return 0;
}