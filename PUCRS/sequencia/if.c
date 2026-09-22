#include <stdio.h>

int main ()
{
    int a , b , c, men, mai;

    printf("Entre a, b, c -> ");
    scanf("%i %i %i", &a, &b, &c);

    if( a < b){
        men = a;
        mai = b;
    }
    else{
        men = b;
        mai = a;
    }

    if ( c < men)
        printf("%i %i %i\n", c, men, mai);

    else
    {
        if( c > mai)
            printf("%i %i %i\n", men, mai, c);
        
        else    
            printf("%i %i %i\n", men, c, mai);
    } 
}