#include<stdio.h>

typedef struct { 
    int length;
    int breadth;
} Rectangle;

/*
Note:

    struct Rectangle {
        int length;
        int breadth;
    };

    struct Rectangle box;

Initialization:
    Rectangle box = {10,20};
*/

int main(){
    Rectangle box;
    box.length = 10;
    box.breadth = 20;
    printf("Area = %d * %d = %d", box.length, box.breadth, box.length * box.breadth);
    return 0;
}