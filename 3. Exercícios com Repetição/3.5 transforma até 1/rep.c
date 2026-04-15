#include <stdio.h>

int main ()
{
    int a, count = 0;

    printf("Entre o numero- ");
    scanf("%i", &a);


    while( a != 1 )
    {
       if (a%2 == 0) a = a/2;
            else a = 3*a + 1;
        count++;
        printf("#%i -> %i\n", count, a);
    }

    printf("Foram necessárias %i transformações\n", count);

}