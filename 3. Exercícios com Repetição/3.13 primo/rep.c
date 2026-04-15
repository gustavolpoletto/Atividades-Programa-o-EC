#include <stdio.h>

int main ()
{
     int a, flag = 0, i = 2;

    printf("Entre o numero- ");
    scanf("%i", &a);


    while( i < a )
    {
       if( a % i  == 0)
       {
        printf("divisivel por %i\n", i);
        flag = 1;
       }
       i++;
    }

    if(flag) printf("Nao eh primo\n");
    else printf("Primo\n");


    

}