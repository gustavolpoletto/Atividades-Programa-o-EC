#include <stdio.h>

int main ()
{
    int a, b, c;

    printf("Coloque os possiveis lados do triangulo - ");
    scanf("%d %d %d", &a, &b, &c);

    a = a*a;
    b = b*b;
    c= c*c;

    if(a + b == c || a + c == b || c + b == a)
        printf("triangulo retangulo\n");
    else
        printf("nao e triangulo retangulo\n");
  
}