#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    ptr = (int *)malloc(10 * sizeof(int)); // ptr = new int[10];

    for (int i = 0; i < 10; i++)
    {
        printf("%d", ptr[i]); // std::cout << ptr[i];
    }

    free(ptr); // delete[] ptr;

    return 0;
}
