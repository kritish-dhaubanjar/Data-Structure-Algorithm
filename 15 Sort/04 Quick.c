#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int A[], int l, int h)
{
  int pivot = A[l];
  int i = l, j = h;

  do
  {
    do
    {
      i++;
    } while (A[i] <= pivot);
    do
    {
      j--;
    } while (A[j] > pivot);

    if (i < j)
    {
      swap(&A[i], &A[j]);
    }

  } while (i < j);

  swap(&A[l], &A[j]);

  return j;
}

void QuickSort(int A[], int l, int h)
{
  if (l < h)
  {
    int j = partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j + 1, h);
  }
}

int main()
{
  int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3, 65535};
  int n = 11, i;

  QuickSort(A, 0, n);

  for (i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
}