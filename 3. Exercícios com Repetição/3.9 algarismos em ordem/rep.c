#include <stdio.h>

int main ()
{
    int a, ultimo, ordem = 0;

    printf("Entre o numero- ");
    scanf("%i", &a);

     while( a > 0 )
    {
        ultimo = a%10;
        a = a /10;
        if( a %10 > ultimo )ordem = 1;
    }

    if (ordem == 0) printf("Digitos em ordem\n");
    else printf("Digitos fora de  ordem\n");
}