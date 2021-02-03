#include <stdio.h>

void B(int);

void A(int a)
{
    if (a > 0)
    {
        printf("%d", a);
        B(a - 1);
    }
}

void B(int b)
{
    if (b > 0)
    {
        printf("%d", b);
        A(b / 2);
    }
}

int main()
{
    A(20);
    return 0;
}