#include <stdio.h>

int *merge(int A[], int l, int m, int h)
{
  int i, j, k;
  i = l;
  j = m + 1;
  k = l;

  int B[h + 1];

  while (i <= m && j <= h)
  {
    if (A[i] < A[j])
    {
      B[k++] = A[i++];
    }
    else
    {
      B[k++] = A[j++];
    }
  }

  for (int a = i; a <= m; a++)
  {
    B[k++] = A[a];
  }

  {
    for (int b = j; b <= h; b++)
    {
      B[k++] = A[b];
    }
  }

  for (i = l; i <= h; i++)
  {
    A[i] = B[i];
  }
}

int main()
{
  int A[] = {2, 5, 8, 12, 3, 6, 7, 10};

  merge(A, 0, 3, 7);

  for (int i = 0; i < 8; i++)
  {
    printf("%d ", A[i]);
  }
}