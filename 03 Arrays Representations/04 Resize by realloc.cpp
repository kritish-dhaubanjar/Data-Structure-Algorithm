#include <iostream>

int main()
{
    int *ptr, *qtr;

    ptr = new int[5];
    qtr = new int[10];

    for (int i = 0; i < 5; i++)
    {
        qtr[i] = ptr[i];
    }

    delete[] ptr;
    qtr = NULL;

    return 0;
}