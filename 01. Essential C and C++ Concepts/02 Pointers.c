#include <stdio.h>

int main()
{
    int a = 10;
    int *ptr; // Declaration
    ptr = &a; // Initialization

    printf("a=%d\n", a);
    printf("&a=%p\n", &a);
    printf("ptr=%p\n", ptr);
    printf("*ptr=%d\n", *ptr); // Derefrencing
    printf("&ptr=%p\n", &ptr);

    return 0;
}
