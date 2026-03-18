#include<stdio.h>

int main ()
{
    int a = 1, b=2 , c= 3, men, mai;

    if( a < b)
    {
        men = a;
        mai = b;
    }
    else{
        men = b;
        mai = a;
    }

    if ( c < men)
        printf("%i %i %i\n", c, men, mai);

    else if( c > mai)
        printf("%i %i %i\n", men, mai, c);

    else    
        printf("%i %i %i\n", men, c, mai);

}