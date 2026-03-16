#include <stdio.h>

int main ()
{
    int a, b, c, meio, men;

    printf("Coloque os valores a, b e c - ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b)
    {
        meio = b;
        men = a;
    }
    else
    {
        meio = a;
        men = b;
    } 

    if ( c < meio && c > men)
        meio = c;
    
    else if ( c < men)
        meio = men;
    
    printf("valor do meio - %d\n", meio);
    
  
    
}