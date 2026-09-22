#include <stdio.h>

int main ()
{
    int a , b , c, men, mai;

    printf("Entre a, b, c -> ");
    scanf("%i %i %i", &a, &b, &c);

    mai = a;
    men = b;

    if( a < b){
        men = a;
        mai = b;
    }

    if ( c < men) men = c;
    if ( c > mai) mai = c;
    
    printf("%i %i %i\n",men, a + b + c - men - mai, mai);
}