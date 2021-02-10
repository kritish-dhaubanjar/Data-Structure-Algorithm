#include <stdio.h>

int main()
{
    long int T, H = 0;
    char *string = "mississippi";

    for (int i = 0; string[i] != '\0'; i++)
    {
        T = 1;
        int shift = string[i] - 97;
        T = T << shift;

        if ((T & H) > 0)
        {
            printf("%c\n", string[i]);
        }
        else
        {
            H = H | T;
        }
    }

    return 0;
}