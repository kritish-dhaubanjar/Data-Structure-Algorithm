#include <iostream>

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 10;
    int b = 20;

    std::cout << "a=" << a << ",b=" << b << "\n";
    swap(a, b);
    std::cout << "a=" << a << ",b=" << b << "\n";

    return 0;
}