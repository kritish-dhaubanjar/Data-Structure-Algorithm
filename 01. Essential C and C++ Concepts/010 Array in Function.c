#include <stdio.h>
#include <stdlib.h>

void multiply(int *A, int size, int of);
void display(int A[], int size, int of);

int main()
{
    int *A = (int *)calloc(10, sizeof(int));

    multiply(A, 10, 2);
    display(A, 10, 2);

    return 0;
}

void multiply(int *A, int size, int of)
{
    for (int i = 0; i < size; i++)
    {
        A[i] = i * of;
    }
}

void display(int A[], int size, int of)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d X %d = %d\n", of, i, A[i]);
    }
}