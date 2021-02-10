#include <stdio.h>

int main()
{
    char *string = "pneumonoultramicroscopicsilicovolcanoconiosis";
    int duplicates[26] = {0}; //a-z

    int len = 0;
    for (; string[len] != '\0'; len++)
    {
        duplicates[string[len] - 97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (duplicates[i] > 0)
            printf("%c : %d\n", i + 97, duplicates[i]);
    }

    return 0;
}