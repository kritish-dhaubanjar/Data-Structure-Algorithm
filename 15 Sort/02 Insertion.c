#include <stdio.h>

int main()
{
  int A[] = {8, 5, 7, 3, 2};

  for (int i = 1; i < 5; i++)
  {
    int x = A[i];
    int j = i - 1;

    for (; j >= 0; j--)
    {
      if (A[j] > x)
      {
        A[j + 1] = A[j];
      }
      else
      {
        break;
      }
    }

    A[j + 1] = x;
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%d", A[i]);
  }
}