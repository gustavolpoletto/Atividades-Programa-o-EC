#include <stdio.h>

int main ()
{
    int ax, ay, r1, bx, by, r2;

    printf("Coloque os valores do circulo 1 (x y raio) - ");
    scanf("%d %d %d", &ax, &ay, &r1);

    printf("Coloque os valores do circulo 2 (x y raio) - ");
    scanf("%d %d %d", &bx, &by, &r2);

    float dist = (float)((ax - bx)*(ax - bx) + (ay - by)*(ay - by));

    if (dist <= (r1 + r2)*(r1 + r2))
        printf("circulos se intersectam");
    else
        printf("circulos nao se intersectam");
  
}