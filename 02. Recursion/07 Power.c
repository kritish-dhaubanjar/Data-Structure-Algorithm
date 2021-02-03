#include <stdio.h>

int power(int base, int exponent)
{
    if (exponent > 0)
        return base * power(base, exponent - 1);
    return 1;
}

int main()
{
    int cube = power(3, 3);
    printf("%d", cube);
    return 0;
}