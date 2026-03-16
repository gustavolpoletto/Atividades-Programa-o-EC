#include <stdio.h>

int main ()
{
    int a, b, c, menor;

    printf("Coloque os valores a, b e c - ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b)
        menor = a;
    else 
        menor = b;
    
    if (c < menor)
        menor = c;


    printf("Menor = %d\n", menor);
    
}