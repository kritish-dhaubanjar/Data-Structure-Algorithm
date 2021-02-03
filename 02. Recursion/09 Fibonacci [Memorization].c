#include <stdio.h>

/*
n=0  1   2   3   4  ...
0	1	1	2	3	5	8	13	21	34	55	89	144	233	377	610	987	1597	2584	4181	6765
*/
int F[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int fibonacci(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return F[n];
    }
    else
    {
        if (F[n - 2] == -1)
            F[n - 2] = fibonacci(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = fibonacci(n - 1);
        return F[n - 2] + F[n - 1];
    }
}

int main()
{
    printf("%d", fibonacci(7));
    return 0;
}