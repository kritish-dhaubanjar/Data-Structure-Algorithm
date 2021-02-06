typedef struct
{
    int *A;
    int size;
    int length;
} Array;

void initialize(Array *, int);
void display(Array);
void append(Array *, int);
void insert(Array *, int, int);
void del(Array *, int);
int search(Array, int);
int binarySearch(Array, int);
int binarySearch_recursive(Array, int, int, int);
int get(Array, int);
void set(Array *, int, int);
//
int max(Array);
int min(Array);
int sum(Array);
float avg(Array);

// More Operation
void reverse_with_copy(Array *);
void reverse_with_double_pointer(Array *);
void insertSort(Array *, int);