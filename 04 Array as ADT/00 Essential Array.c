#include <stdio.h>
#include <stdlib.h>

int *newArray()
{
    /*
    we return address of a local variable which is not 
    advised as local variables may not exist in memory 
    after function call is over.

    int A[10] = {0};
    return A;
    */
    return (int *)malloc(10 * sizeof(int));
}

int main()
{
    int *X = newArray();
    return 0;
}
