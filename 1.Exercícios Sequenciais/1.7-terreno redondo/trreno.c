#include <stdio.h>

#define PI 3.1415
#define sqr(x) ((x) * (x))
#define cir(x) (PI*sqr(x))

void main ()
{
    int raio_terreno = 15, raio_casa = 7;
    
    int terreno = cir(raio_terreno);
    float casa = cir(raio_casa);
    
    int livre = terreno - casa;
    
    float porcentagem = (float)livre / terreno *100;
    
    printf("Area terreno = %d\nArea casa = %f\nLivre = %d\nPorcentagem Livre = %f", terreno, casa, livre, porcentagem);
    
}
