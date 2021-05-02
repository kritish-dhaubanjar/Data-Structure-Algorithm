#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// STACK START

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(char x)
{
    Node *t;
    t = (Node *)malloc(sizeof(Node));
    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    Node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// STACK END

int isOperand(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    else
        return 1;
}

int eval(char *postfix)
{
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push((postfix[i] - '0'));
        }
        else
        {
            int y = pop();
            int x = pop();
            int z = 0;
            switch (postfix[i])
            {
            case '+':
                z = x + y;
                break;
            case '-':
                z = x - y;
                break;
            case '*':
                z = x * y;
                break;
            case '/':
                z = x / y;
                break;
            }

            push(z);
        }
    }
    return top->data;
}

int main()
{

    char *postfix = "234*+82/-";

    int result = eval(postfix);

    printf("%d", result);

    return 0;
}