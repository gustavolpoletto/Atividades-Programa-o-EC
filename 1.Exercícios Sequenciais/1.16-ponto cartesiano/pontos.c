#include <stdio.h>
#include <math.h>

#define sqr(x) ((x)*(x))

typedef struct{
    int x;
    int y;
}ponto;

void main ()
{
    ponto a, b;
    a.x = 3;
    a.y = 5;

    b.x = 4;
    b.y = 6;

    //distancia entre os pontos
    float dist = sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));

    printf("distancia => %.3f\n", dist);
    
    //inclinação da reta
    
    float inc = (float)(b.y - a.y) / (b.x - a.x);
    printf("Inclinacao => %.3f\n", inc);
    
}
