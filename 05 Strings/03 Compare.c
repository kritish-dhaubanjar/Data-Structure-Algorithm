#include <stdio.h>

int toLowerCase(char *);
int compare(char *, char *);

int main()
{
    char a[128] = "apples";
    char b[128] = "AppLES";

    int len_a = toLowerCase(a);
    int len_b = toLowerCase(b);

    printf("a: %s\n", a);
    printf("len_a: %d\n", len_a);
    printf("b: %s\n", b);
    printf("len_b: %d\n", len_b);

    int result = compare(a, b);
    printf("compare: %d", result);
    return 0;
}

int toLowerCase(char *x)
{
    int len = 0;
    for (; x[len] != '\0'; len++)
    {
        if (x[len] >= 'A' && x[len] <= 'Z')
        {
            x[len] = x[len] + 32;
        }
    }
    return len;
}

int compare(char *a, char *b)
{
    int i, j;
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] > b[j])
            return 1;
        else if (a[i] < b[j])
            return -1;
    }

    if (a[i] == '\0' && b[j] == '\0')
        return 0;
    else if (a[i] == '\0')
        return -1;
    else if (b[j] == '\0')
        return 1;
}