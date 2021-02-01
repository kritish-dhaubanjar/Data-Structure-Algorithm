#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    //alias r=a

    cout << "a=" << a << "\n";
    cout << "&a=" << &a << "\n";
    cout << "r=" << r << "\n";
    cout << "&r=" << &r;

    return 0;
}