#include <stdio.h>

int main ()
{
    int a, res = 0;

    printf("Entre o numero- ");
    scanf("%i", &a);


    while( a > 0 )
    {
       res += a %10;
       a = a /10;
    }

    printf("Resultado = %i\n", res);

}