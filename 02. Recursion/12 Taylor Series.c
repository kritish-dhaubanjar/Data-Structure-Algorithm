#include <stdio.h>
float taylor(int x, int n)
{
    static int p = 1, f = 1;
    if (n == 0)
        return 1;
    int r = taylor(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

int main()
{
    printf("%f", taylor(2, 4));
    return 0;
}

/*
    taylor(2,4) return (((1+x/1) + x^2/2) + x^3/6) + x^4/12
    taylor(2,3) return ((1+x/1) + x^2/2) + x^3/6
    taylor(2,2) return (1+x/1) + x^2/2
    taylor(2,1) return r + p/f => 1 + x/1
    taylor(2,0) return 1
*/