/*
        Pascal's Triangle
               0C0
                1
              /   \
            1       1
          1C0       1C1       
        1       2       1
      2C0      2C1       2C2
    1       3       3       1
  3C0     3C1      3C2      3C3
1       4       6       4       1   
4C0    4C1     4C2      4C3      4C4   

r=0 => 1
n==r => 1

*/

#include <stdio.h>

int nCr(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
    printf("%d", nCr(4, 2));
    return 0;
}