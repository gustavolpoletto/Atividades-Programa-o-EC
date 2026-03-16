#include <stdio.h>

int main ()
{
    int a, b;
    float total;

    printf("Coloque os valores dos dois produtos - ");
    scanf("%d %d", &a, &b);

    if (a < b)
        total = 0.5 * a + b;
    else 
        total = 0.5 * b + a;
        
    printf ("total a ser pago - R$%.2f", total);
}