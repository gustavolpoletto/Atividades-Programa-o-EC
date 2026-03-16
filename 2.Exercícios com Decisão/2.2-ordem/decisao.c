#include <stdio.h>

int main ()
{
    int a, b, c;

    printf("Coloque os valores a, b e c - ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && b < c)
        printf("Os numeros estao em ordem\n");
    else 
        printf("os Numeros nao estao em ordem\n");
    
  
    
}