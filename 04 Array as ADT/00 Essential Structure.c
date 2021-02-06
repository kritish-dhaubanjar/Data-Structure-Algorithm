#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int flag;
    int *A;
} Sample;

void passByValue(Sample);
void passByReference(Sample *);
void show(Sample);

int main()
{
    Sample sample;
    //
    sample.flag = 1;
    sample.A = (int *)malloc(10 * sizeof(int));

    show(sample);

    printf("\npassByValue(sample)\n");
    passByValue(sample);
    show(sample);

    printf("\npassByReference(&sample)\n");
    passByReference(&sample);
    show(sample);

    free(sample.A);

    return 0;
}

void passByValue(Sample sample)
{
    sample.flag = 100;
    for (int i = 0; i < 10; i++)
    {
        sample.A[i] = 100 + i;
    }
}

void passByReference(Sample *sample)
{
    sample->flag = 200;
    for (int i = 0; i < 10; i++)
    {
        sample->A[i] = 200 + i;
    }
}

void show(Sample sample)
{
    printf("sample.flag=%d\n", sample.flag);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", sample.A[i]);
    }
    printf("\n");
}
