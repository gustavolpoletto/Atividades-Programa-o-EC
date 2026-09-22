#include <stdio.h>

int main ()
{
    float a, b, c, d;

    printf("Coloque as notas em ordem - ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    
    if(d == 0)
        printf("Precisa de %.2f pontos", 28-a-b-c);
    else
        printf("Média %.2f pontos", (a+b+c+d)/4);
}