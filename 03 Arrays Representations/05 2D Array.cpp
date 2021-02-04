#include <iostream>

int main()
{
    /*
    1. A[3][4] 
    Stack [A00, A01, A02, A03, A10, A11, A12, A13, A20, A21, A22, A23] Row Major Mapping
    */

    int A[3][4];

    /*
    2. Stack      Heap
        ____     ____________
       |___| -> |__|__|__|__|
       |___| -> |__|__|__|__|
       |___| -> |__|__|__|__|
   */

    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    /*
    4. 
        Stack
         ___
        |__|

        Heap      Heap
        ____     ____________
       |___| -> |__|__|__|__|
       |___| -> |__|__|__|__|
       |___| -> |__|__|__|__|
   */

    int **C;

    C = new int *[3];

    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    delete[] C;

    return 0;
}