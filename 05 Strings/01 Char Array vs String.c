#include <stdio.h>

int main()
{
    char charArray[50] = {'A', 'E', 'I', 'O', 'U'};
    char string[50] = {'A', 'E', 'I', 'O', 'U', '\0'};
    char *heapString = "aeiou";
    char *inputString;

    printf("charArray: %s\n", charArray);
    printf("string: %s\n", string);
    printf("heapString: %s\n", heapString);

    // fgets(inputString, 50, stdin);
    gets(inputString);
    printf("inputString: %s\n", inputString);

    return 0;
}