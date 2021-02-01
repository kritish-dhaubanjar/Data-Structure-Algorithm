#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    C++
    ptr = new int[10];
    */
    int *ptr;
    ptr = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        ptr[i] = i;
    }

    //Pointer
    int *tmp = ptr;

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", *tmp);
        tmp++;
    }

    //Pointer & Array
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", ptr[i]);
    }

    free(ptr);
    return 0;
}