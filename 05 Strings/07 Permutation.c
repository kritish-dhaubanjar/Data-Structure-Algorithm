#include <stdio.h>

void permutation(char *, int);

int main()
{
    char S[4] = {'A', 'B', 'C', '\0'};

    permutation(S, 0);

    return 0;
}

void permutation(char *S, int k)
{
    static int A[4] = {0};
    static char R[4];

    if (S[k] == '\0')
        printf("%s\n", R);
    else
        for (int i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                A[i] = 1;
                R[k] = S[i];
                permutation(S, k + 1);
                A[i] = 0;
            }
        }
}