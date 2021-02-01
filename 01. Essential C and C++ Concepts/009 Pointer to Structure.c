#include <stdio.h>

typedef struct
{
    int length;
    int breadth;
} Rectangle;

int main()
{
    Rectangle box;
    Rectangle *ptr;

    ptr = &box;

    /*
    (*ptr).length = 10;
          ^ Higher Precedance  
    (*ptr).breadth = 20;
    */

    ptr->length = 10;
    ptr->breadth = 20;

    printf("Area = %d * %d = %d", (*ptr).length, (*ptr).breadth, ptr->length * ptr->breadth);
    return 0;
}