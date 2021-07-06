#include <stdio.h>

int main()
{
  int A[] = {8, 5, 7, 3, 2};

  int i = 0, j = 0, k = 0;

  for (; i < 4; i++)
  {
    j = k = i + 1;

    for (; j < 5; j++)
    {
      if (A[i] > A[j])
      {
        k = j;
      }
    }
    int temp = A[i];
    A[i] = A[k];
    A[k] = temp;
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%d", A[i]);
  }
}