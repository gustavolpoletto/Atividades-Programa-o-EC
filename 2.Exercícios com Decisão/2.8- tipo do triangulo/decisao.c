#include <stdio.h>

int main ()
{
    int a, b, c;

    printf("Coloque os valores a, b e c - ");
    scanf("%d %d %d", &a, &b, &c);

    if (a == b && b==c)
       printf("Triangulo equilatero");
       
    else if (a==b || a==c || b==c)
       printf("Triangulo isosceles");

    else if( a + b <= c || b + c <= a || a + c <= b)
        printf("nao e triangulo");
    else 
        printf("tiangulo escaleno");
  
}