#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *newNode(int data)
{
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insert(Node **node, int data)
{
  Node *t = newNode(data);
  Node *head = *node, *tail = NULL;

  if (head == NULL)
  {
    *node = t;
    return;
  }

  while (head)
  {
    tail = head;
    head = head->next;
  }

  tail->next = t;
}

int destroy(Node **node)
{
  if (*node == NULL)
    return -1;

  int data = (*node)->data;
  *node = (*node)->next;
  return data;
}

int findMax(int A[], int n)
{
  int max = INT_MIN;
  int i;
  for (i = 0; i < n; i++)
  {
    if (A[i] > max)
      max = A[i];
  }
  return max;
}

void binSort(int A[], int n)
{
  int max = findMax(A, n);
  Node *bins[10];

  for (int i = 0; i < 10; i++)
    bins[i] = NULL;

  int times = 0;
  while (max > 0)
  {
    times++;
    max = max / 10;
  }

  for (int time = 0; time < times; time++)
  {

    for (int i = 0; i < n; i++)
    {
      //pow(10, time)
      int divide = 1;
      for (int i = 0; i < time; i++)
        divide = divide * 10;

      int index = (A[i] / divide) % 10;
      insert(&bins[index], A[i]);
    }

    int i = 0, j = 0;
    while (i < 10)
    {
      while (bins[i] != NULL)
      {
        A[j++] = destroy(&bins[i]);
      }
      i++;
    }
  }
}

int main()
{
  int A[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};

  binSort(A, 10);

  for (int i = 0; i < 10; i++)
    printf("%d ", A[i]);
  return 0;
}