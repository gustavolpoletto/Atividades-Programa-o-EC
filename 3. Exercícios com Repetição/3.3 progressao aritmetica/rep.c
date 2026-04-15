#include <stdio.h>

int main ()
{
    int a, b, n, res = 0, i = 0;

    printf("Entre os numeros a e b e o numero de termos- ");
    scanf("%i %i %i", &a, &b, &n);

    if (b < a)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while( i < n )
    {
        res = res + a + (b*i);
        i ++;
    }

    printf("Resultado = %i\n", res);

}