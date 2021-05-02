#include <iostream>
#include "01_Stack.h"

template <class T>
Stack<T>::Stack(int size)
{
    this->top = -1;
    this->size = size;
    this->S = new T[size];
}

template <class T>
bool Stack<T>::isEmpty()
{
    return this->top == -1;
}

template <class T>
bool Stack<T>::isFull()
{
    return this->top == this->size - 1;
}

template <class T>
void Stack<T>::push(T el)
{
    if (this->isFull())
    {
        std::cout << "Stack Overflow\n";
    }
    else
    {
        this->S[++this->top] = el;
    }
}

template <class T>
T Stack<T>::pop()
{
    T el = -1;
    if (this->isEmpty())
        std::cout << "Stack Underflow\n";
    else
    {
        el = this->S[this->top];
        this->top--;
    }
    return el;
}

template <class T>
T Stack<T>::peek(int pos)
{
    return this->S[this->top - pos + 1];
}

int main()
{
    Stack<int> stack(10);

    for (int i = 0; i < 15; i++)
    {
        stack.push(i);
    }

    for (int i = 0; i < 15; i++)
    {
        std::cout << stack.pop() << "\n";
    }

    return 0;
}