template <class T>
class Stack
{
private:
    T *S;
    int top;
    int size;

public:
    Stack(int);
    bool isFull();
    bool isEmpty();
    void push(T);
    T pop();
    T peek(int pos);
};
