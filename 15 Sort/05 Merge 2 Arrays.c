#include <stdio.h>

int *merge(int A[], int B[], int m, int n, int C[])
{
  int i, j, k;
  i = j = k = 0;

  while (i < m && j < n)
  {
    if (A[i] < B[j])
    {
      C[k++] = A[i++];
    }
    else
    {
      C[k++] = B[j++];
    }
  }

  if (i < m)
  {
    for (int a = i; a < m; a++)
    {
      C[k++] = A[a];
    }
  }

  if (j < n)
  {
    for (int b = j; b < n; b++)
    {
      C[k++] = B[b];
    }
  }

  return C;
}

int main()
{
  int A[] = {2, 10, 18, 20, 23, 29};
  int B[] = {4, 9, 19, 25};

  int C[6 + 4];
  merge(A, B, 6, 4, C);

  for (int i = 0; i < 6 + 4; i++)
  {
    printf("%d ", C[i]);
  }
}