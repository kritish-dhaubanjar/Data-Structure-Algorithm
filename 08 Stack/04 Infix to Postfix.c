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

int precedance(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

char *infixToPostfix(char *infix)
{
    int i = 0, j = 0;

    int length = strlen(infix);
    char *postfix = (char *)malloc((length + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (top)
        {
            if (precedance(infix[i]) > precedance(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
        else
        {
            push(infix[i++]);
        }
    }

    while (top != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";

    char *postfix = infixToPostfix(infix);

    printf("%s", postfix);

    return 0;
}