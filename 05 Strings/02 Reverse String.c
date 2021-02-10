#include <stdio.h>

int main()
{
    char sentence[128];
    printf("sentence: ");
    fgets(sentence, 128, stdin);

    int len = 0;
    for (; sentence[len] != '\0' && sentence[len] != '\n'; len++)
        ;

    printf("len: %d\n", len);

    for (int i = 0, j = len - 1 - 1; i < j; i++, j--)
    {
        char temp = sentence[i];
        sentence[i] = sentence[j];
        sentence[j] = temp;
    }

    printf("reverse sentence: %s", sentence);

    return 0;
}