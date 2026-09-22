#include <stdio.h>

int main ()
{
    int ano, sec;

    printf("Entre o ano - ");
    scanf("%i", &ano);
    sec = ano / 100;
    if (ano % 100 != 0) sec++;

    printf("Seculo %i\n", sec);

    
}