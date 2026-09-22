#include <stdio.h>

int main ()
{
    int a, count = 0;


    for(int i = 1000000; i<=10000000; i++)
    {
        a = i;
        while( a > 0 )
        {
            if( a %100 == 33)count += 1;
            a = a /10;
        }
    }

    printf("ha %i numeros com 33!!\n", count);

}