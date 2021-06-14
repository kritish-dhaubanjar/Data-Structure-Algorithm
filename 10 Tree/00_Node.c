#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node
{
  int data;
} Node;

int main()
{
  // Main Node
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = 102;

  // Array of 10 Nodes
  Node *nodes = (Node *)malloc(SIZE * sizeof(Node));
  nodes[0] = *node;

  // Changes to copy of node
  ++nodes[0].data;
  printf("nodes[0].data = %d\nnode->data = %d\n", nodes[0].data, node->data);

  // Array of 10 Node Pointers
  Node **nodePtrs = (Node **)malloc(SIZE * sizeof(Node));
  nodePtrs[0] = node;

  // Changes to node via pointer
  ++nodePtrs[0]->data;
  printf("nodesPtr[0]->data = %d\nnode->data = %d\n", nodePtrs[0]->data, node->data);

  return 0;
}