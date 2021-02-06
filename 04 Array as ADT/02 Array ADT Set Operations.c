#include <stdio.h>
#include <stdlib.h>

int *Union(int[], int, int[], int);
int *Intersection(int[], int, int[], int);
int *Difference(int[], int, int[], int);

void display(int[], int);

int main()
{
    int A[5] = {2, 4, 6, 8, 10};
    int B[7] = {1, 3, 4, 5, 7, 8, 9};

    int *C = Union(A, 5, B, 7);
    display(C, 10);

    int *D = Intersection(A, 5, B, 7);
    display(D, 2);

    int *E = Intersection(B, 7, A, 5);
    display(E, 2);

    int *F = Difference(A, 5, B, 7);
    display(F, 3);

    int *G = Difference(B, 7, A, 5);
    display(G, 5);

    free(C);
    free(D);
    free(E);
    free(F);
    free(G);

    return 0;
}

void display(int C[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", C[i]);
    }
    printf("\n");
}

int *Union(int A[], int len_A, int B[], int len_B)
{

    int *C = (int *)malloc((len_A + len_B) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < len_A && j < len_B)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
            //C[k] = A[i];
            // i++;
            // k++;
        }
        else if (A[i] > B[j])
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }

    if (i < len_A)
    {
        for (; i < len_A; i++, k++)
        {
            C[k] = A[i];
        }
    }

    if (j < len_B)
    {
        for (; j < len_B; i++, k++)
        {
            C[k] = B[j];
        }
    }

    printf("n(A U B) = %d\n", k);

    return C;
}

int *Intersection(int A[], int len_A, int B[], int len_B)
{
    int *C = (int *)calloc(len_A, sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < len_A)
    {
        if (A[i] < B[j])
        {
            // C[k++] = A[i++];
            i++;
        }
        else if (A[i] > B[j])
        {
            // C[k++] = B[j++];
            j++;
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }

    printf("n(A I B) = %d\n", k);

    return C;
}

int *Difference(int A[], int len_A, int B[], int len_B)
{
    int *C = (int *)calloc(len_A, sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < len_A)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (A[i] > B[j])
        {
            // C[k++] = B[j++];
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    printf("n(A - B) = %d\n", k);

    return C;
}