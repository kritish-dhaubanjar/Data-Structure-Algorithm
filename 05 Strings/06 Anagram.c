#include <stdio.h>

int main()
{
    char *a = "decimal";
    char *b = "medical";

    int occur[26] = {0};

    for (int i = 0; a[i] != '\0'; i++)
    {
        occur[a[i] - 97]++;
    }

    for (int i = 0; b[i] != '\0'; i++)
    {
        occur[b[i] - 97]--;
        if (occur[b[i] - 97] < 0)
        {
            printf("Not Anagram");
            return 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (occur[i] != 0)
        {
            printf("Not Anagram");
            return 0;
        }
    }

    printf("Anagram");
    return 0;
}