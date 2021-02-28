struct Node
{
    int data;
    struct Node *next;
}; // *head = NULL

void create(int A[], int size);
void display(struct Node *p);
void recursiveDisplay(struct Node *p);
void recursivReverseDisplay(struct Node *p);
//
int recursiveCount(struct Node *p);
int recursiveSum(struct Node *p);
//
int max(struct Node *p);
