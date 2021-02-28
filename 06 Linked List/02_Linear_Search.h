struct Node
{
    int data;
    struct Node *next;
};

void create(int A[], int size);
void display(struct Node *p);
struct Node *linearSearch(struct Node *head, int key);
struct Node *recursiveLinearSearch(struct Node *head, int key);
struct Node *improvedLinearSearch(struct Node *head, int key);