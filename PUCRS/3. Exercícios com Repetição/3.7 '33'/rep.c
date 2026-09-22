#include <stdio.h>

int main ()
{
    int a, flag = 0;

    printf("Entre o numero- ");
    scanf("%i", &a);


    while( a > 0 )
    {
       if( a %100 == 33)flag = 1;
       a = a /10;
    }

    if(flag) printf("Possui 33\n");
    else printf("NAO Possui 33\n");

}