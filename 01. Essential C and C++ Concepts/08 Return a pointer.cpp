#include <iostream>

int *max(int &a, int &b)
{
    return a > b ? &a : &b;
}

int main()
{
    int a = 10;
    int b = 20;

    *(max(a, b)) = 100;

    std::cout << "a=" << a << ",b=" << b;
    return 0;
}