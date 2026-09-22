#include <stdio.h>

int main ()
{
    char a;
    int b;

    printf("Coloque as Coordenadas do quadrado - ");
    scanf("%c %d", &a, &b);

    a = a - 'a' + 1;

    if((a + b ) % 2 == 0)
        printf("Preto\n");
    else
        printf("Branco\n");
  
}