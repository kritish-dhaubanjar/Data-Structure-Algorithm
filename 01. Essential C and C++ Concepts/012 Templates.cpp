#include <iostream>

template <class T>
class Rectangle
{
private:
    T length;
    T breadth;

public:
    Rectangle() {}
    Rectangle(T l, T b);
    T area();
};

template <class T>
Rectangle<T>::Rectangle(T l, T b)
{
    this->length = l;
    this->breadth = b;
}

template <class T>
T Rectangle<T>::area()
{
    return this->length * this->breadth;
}

int main()
{
    Rectangle<int> rec1 = Rectangle<int>(10, 20);
    Rectangle<float> rec2 = Rectangle<float>(10.0, 20.0);

    printf("Area = %d\n", rec1.area());
    printf("Area = %f", rec2.area());

    return 0;
}