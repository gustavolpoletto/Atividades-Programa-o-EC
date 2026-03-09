#include <stdio.h>



void main ()
{
    int dinheiro, notas = 0;

    printf("Quantos Reais devem ser pagos?\n - ");
    scanf("%i", &dinheiro);


    while (dinheiro >= 100)
    {
        dinheiro-= 100;
        notas++;
    }
    while (dinheiro >= 50)
    {
        dinheiro-= 50;
        notas++;
    }
    while (dinheiro >= 10)
    {
        dinheiro-= 10;
        notas++;
    }
    while (dinheiro >= 5)
    {
        dinheiro-= 5;
        notas++;
    }
    while (dinheiro >= 1)
    {
        dinheiro-= 1;
        notas++;
    }

    printf("O minimo de notas a serem entreges e %d", notas);
}
