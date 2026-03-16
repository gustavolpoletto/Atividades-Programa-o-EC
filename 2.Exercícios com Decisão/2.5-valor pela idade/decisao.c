#include <stdio.h>

int main ()
{
    int idade;

    printf("Coloque a idade - ");
    scanf("%d", &idade);

    if (idade <= 7)
    {
        printf ("ingresso - R$5,00\n");
    }

    else if (idade > 7 && idade <= 18)
    {
        printf ("ingresso - R$10,00\n");
    }

    else if (idade > 59)
    {
        printf ("ingresso - R$8,00\n");
    }

    else
    {
        printf ("ingresso - R$12,00\n");
    }

}