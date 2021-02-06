#include <stdio.h>
#include <stdlib.h>
#include "01_Array_ADT.h"

int main()
{
    Array array;
    initialize(&array, 10);

    append(&array, 100);
    append(&array, 101);
    append(&array, 102);
    append(&array, 103);
    append(&array, 104);
    append(&array, 105);
    display(array);

    printf("\ninsert(&array, 2, 666)\n");
    insert(&array, 2, 666);
    display(array);

    printf("\ndel(&array, 2)\n");
    del(&array, 2);
    display(array);

    printf("\nsearch(array, 102)\n");
    printf("%d\n", search(array, 102));

    printf("\nsearch(array, 102)\n");
    printf("%d\n", search(array, 102));

    printf("\nbinarySearch(array, 105)\n");
    printf("%d\n", binarySearch(array, 105));

    printf("\nbinarySearch(array, 666)\n");
    printf("%d\n", binarySearch(array, 666));

    printf("\nbinarySearch_recursive(array, 105)\n");
    printf("%d\n", binarySearch_recursive(array, 105, 0, array.length - 1));

    printf("\nbinarySearch_recursive_recursive(array, 666)\n");
    printf("%d\n", binarySearch_recursive(array, 666, 0, array.length - 1));

    printf("\nget(array, 3)\n");
    printf("%d\n", get(array, 3));

    printf("\nget(array, 106)\n");
    printf("%d\n", get(array, 106));

    printf("\nset(array, 2,666)\n");
    set(&array, 3, 666);
    display(array);

    printf("\nmax(array)\n");
    printf("%d", max(array));

    printf("\nmin(array)\n");
    printf("%d", min(array));

    printf("\nsum(array)\n");
    printf("%d", sum(array));

    printf("\navg(array)\n");
    printf("%f\n", avg(array));

    printf("\nreverse_with_copy(array)\n");
    reverse_with_copy(&array);
    display(array);

    printf("\nreverse_with_double_pointer(array)\n");
    reverse_with_double_pointer(&array);
    display(array);

    printf("\ndel(&array, 2)\n");
    del(&array, 3);
    display(array);

    printf("\ninsertSort(&array, 50)\n");
    insertSort(&array, 50);
    display(array);

    printf("\n");

    free(array.A);
    return 0;
}

void initialize(Array *array, int size)
{
    array->length = 0;
    array->size = size;
    array->A = (int *)malloc(size * sizeof(int));
}

void display(Array array)
{
    printf("size=%d\n", array.size);
    printf("length=%d\n", array.length);
    for (int i = 0; i < array.length; i++)
    {
        printf("[%d]=%d\n", i, array.A[i]);
    }
}

void append(Array *array, int n)
{
    if (array->length < array->size)
    {
        array->A[array->length] = n;
        array->length++;
    }
}

void insert(Array *array, int index, int n)
{
    if (index < array->length && array->length < array->size - 1 && index >= 0)
    {
        for (int i = array->length; i > index; i--)
        {
            array->A[i] = array->A[i - 1];
        }
        array->A[index] = n;
        array->length++;
    }
}

void del(Array *array, int index)
{
    if (index < array->length && index >= 0)
    {
        for (int i = index; i < array->length - 1; i++)
        {
            array->A[i] = array->A[i + 1];
        }
        array->length--;
    }
}

int search(Array array, int key)
{
    for (int i = 0; i < array.length; i++)
    {
        if (array.A[i] == key)
        {
            return i;
            break;
        }
    }

    return -1;
}

int binarySearch(Array array, int key)
{
    int low = 0;
    int high = array.length - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array.A[mid] == key)
        {
            return mid;
        }
        else if (array.A[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int binarySearch_recursive(Array array, int key, int low, int high)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (array.A[mid] == key)
        return mid;
    else if (array.A[mid] > key)
        return binarySearch_recursive(array, key, low, mid - 1);
    else
        return binarySearch_recursive(array, key, mid + 1, high);
}

int get(Array array, int index)
{
    if (index >= 0 && index < array.length)
    {
        return array.A[index];
    }
    return -1;
}

void set(Array *array, int index, int value)
{
    if (index >= 0 && index < array->length)
    {
        array->A[index] = value;
    }
}

int max(Array array)
{
    int max;
    if (array.length >= 0)
    {
        max = array.A[0];

        for (int i = 1; i < array.length; i++)
        {
            if (array.A[i] > max)
                max = array.A[i];
        }
    }
    return max;
}

int min(Array array)
{
    int min;
    if (array.length >= 0)
    {
        min = array.A[0];

        for (int i = 1; i < array.length; i++)
        {
            if (array.A[i] < min)
                min = array.A[i];
        }
    }
    return min;
}

int sum(Array array)
{
    int sum = 0;

    for (int i = 0; i < array.length; i++)
    {
        sum += array.A[i];
    }
    return sum;
}

float avg(Array array)
{
    if (array.length > 0)
        return sum(array) / (float)array.length;
    return 0;
}
//
void reverse_with_copy(Array *array)
{
    int B[array->length];

    for (int i = 0, j = array->length - 1; i < array->length; i++, j--)
    {
        B[i] = array->A[j];
    }

    for (int i = 0; i < array->length; i++)
    {
        array->A[i] = B[i];
    }
}

void reverse_with_double_pointer(Array *array)
{
    for (int i = 0, j = array->length - 1; i < j; i++, j--)
    {
        int tmp = array->A[i];
        array->A[i] = array->A[j];
        array->A[j] = tmp;
    }
}

void insertSort(Array *array, int n)
{
    if (array->length == array->size)
        return;

    int i = array->length - 1;
    while (i >= 0 && array->A[i] > n)
    {
        array->A[i + 1] = array->A[i];
        i--;
    }

    array->A[i + 1] = n;
    array->length++;
}