#include <stdio.h>

int main ()
{
    int a, b, soma = 0;

    printf("Entre os numeros a e b - ");
    scanf("%i %i", &a, &b);

    if (b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while( a <= b )
    {
        soma += a;
        a++;
    }

    printf("Soma = %i", soma);

}