#include <stdio.h>

int *max(int *a, int *b)
{
    return *a > *b ? a : b;
}

int main()
{
    int a = 10;
    int b = 20;

    *(max(&a, &b)) = 100;

    printf("a=%d, b=%d", a, b);

    return 0;
}