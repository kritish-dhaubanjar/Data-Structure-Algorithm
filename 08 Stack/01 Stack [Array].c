#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int top;
    int *S;
} Stack;

void init(Stack *stack, int size)
{
    stack->size = size;
    stack->top = -1;
    stack->S = malloc(sizeof(int) * size);
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == stack->size - 1;
}

void push(Stack *stack, int el)
{
    if (!isFull(stack))
    {
        stack->S[++stack->top] = el;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        int el = stack->S[stack->top];
        stack->top--;
        return el;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int peek(Stack *stack, int pos)
{
    if (!isEmpty(stack))
    {
        return stack->S[stack->top - pos + 1];
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int main()
{
    Stack stack;
    int size = 10;

    init(&stack, size);

    for (int i = 0; i < 15; i++)
    {
        push(&stack, i);
    }

    for (int i = 0; i < 15; i++)
    {
        printf("%d\n", pop(&stack));
    }

    return 0;
}