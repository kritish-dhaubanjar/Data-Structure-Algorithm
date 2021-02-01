#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int length;
    int breadth;
    int area;
} Rectangle;

void calc(Rectangle *rec);

int main()
{
    Rectangle rec = {10, 20, 0};
    Rectangle *ptr = &rec;

    calc(ptr);

    printf("Area=%d", ptr->area);
    return 0;
}

void calc(Rectangle *rec)
{
    rec->area = rec->length * rec->breadth;
}
