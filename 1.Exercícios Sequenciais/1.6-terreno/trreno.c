#include <stdio.h>


void main ()
{
    int larg_terreno = 50, prof_terreno = 30, larg_casa = 15, prof_casa = 10;
    
    int terreno = (larg_terreno * prof_terreno), casa = (larg_casa*prof_casa);
    
    int livre = terreno - casa;

    float porcentagem = (float)livre / terreno *100;

    printf("Area terreno = %d\nArea casa = %d\nLivre = %d\nPorcentagem Livre = %f", terreno, casa, livre, porcentagem);

    
}
