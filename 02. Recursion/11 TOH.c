/*
    TOH(n disk, src, aux, dest)

    1 Disk:
    - TOH(1,A,B,C)

      |           |           |
      |          |           |
    _____       |           |
    ------------------------------
     A          B           C
    
    2 Disk: TOH(2,A,B,C)
    - TOH(1,A,C,B)
    - TOH(1,A,B,C)
    - TOH(1,B,A,C)

      |         |           |
     ---        |           |
    _____       |           |
    ------------------------------
     A          B           C

    3 Disk: TOH(3,A,B,C)
    - TOH(2,A,C,B)
    - TOH(1,A,B,C)
    - TOH(2,B,A,C)

      -         |           |
     ---        |           |
    _____       |           |
    ------------------------------
     A          B           C


*/

#include <stdio.h>

void TOH(int n, char A, char B, char C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("%c->%c\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    TOH(3, 'A', 'B', 'C');
    return 0;
}