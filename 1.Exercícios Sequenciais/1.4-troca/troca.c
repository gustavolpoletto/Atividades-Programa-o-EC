#include <stdio.h>

void pointer_swap (int* a, int* b);

void main ()
{
    int a = 5;
    int b = 11;
    printf("a: %d, b: %d\n", a, b );

    pointer_swap(&a, &b);

    printf("a: %d, b: %d\n", a, b );
}

void pointer_swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}