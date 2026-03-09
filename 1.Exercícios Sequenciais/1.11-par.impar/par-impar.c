#include <stdio.h>

void main ()
{
    int par = 0, impar = 0, quantidade, num;

    printf("Quantos numeros serao analisados?\n - ");
    scanf("%i", &quantidade);

    for ( int i = 0; i < quantidade; i++)
    {
        printf("Numero %i - ", i+1);
        scanf("%i", &num);

        (num % 2 == 0)? par++ : impar++;
    }

    printf("\n%d Pares\n%d Impares\n", par, impar);
}
