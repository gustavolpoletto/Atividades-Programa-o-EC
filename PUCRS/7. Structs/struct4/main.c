#include <stdio.h>

#define MAXTERRENOS 100

struct terreno{
    int base, lado;
};

void printTerreno(int num, struct terreno a){
    printf("%d-%dx%d\n", num, a.base, a.lado);
}

void terrenosQuadrados(struct terreno terrenos[]){
    printf("--Terrenos Quadrados--\n");
    for (int i = 0 ; i <  MAXTERRENOS ; i++ ){
        if (terrenos[i].base == 0 && terrenos[i].lado == 0 ) continue;
        if (terrenos[i].base == terrenos[i].lado ) printTerreno(i, terrenos[i]);
    }
}

void maiorPerimetro(struct terreno terrenos[]){
    int pos = -1, per = -1;
    for (int i = 0 ; i <  MAXTERRENOS ; i++ ){
        int per_atual = 2 * terrenos[i].base + 2 * terrenos[i].lado;
        if ( per_atual > per ) {
            per = per_atual;
            pos = i;
        }
    }
    
    if (pos == -1) return; 
    
    printf("--Maior Perimetro--\n");
    printTerreno(pos, terrenos[pos]);
}

void TerrenoQuaseQuadrado(struct terreno terrenos[]){
    int pos = -1, dif = 10000;
    for (int i = 0 ; i <  MAXTERRENOS ; i++ ){
        int dif_atual = terrenos[i].base - terrenos[i].lado;
        if (dif_atual < 0) dif_atual = - dif_atual;
        
        if ( dif_atual < dif && dif_atual != 0 ) {
            dif = dif_atual;
            pos = i;
        }
        
    }
    
    if (pos == -1) return; 
    
    printf("--Quase Quadrado--\n");
    printTerreno(pos, terrenos[pos]);
}

void TerrenoPiorQuadrado(struct terreno terrenos[]){
    int pos = -1, dif = -1;
    for (int i = 0 ; i <  MAXTERRENOS ; i++ ){
        int dif_atual = terrenos[i].base - terrenos[i].lado;
        if (dif_atual < 0) dif_atual = - dif_atual;
        
        if ( dif_atual > dif && dif_atual != 0 ) {
            dif = dif_atual;
            pos = i;
        }
        
    }
    
    if (pos == -1) return; 
    
    printf("--Pior Quadrado--\n");
    printTerreno(pos, terrenos[pos]);
}

int main()
{
    struct terreno ter[MAXTERRENOS] = {
        {10, 10},   // quadrado
        {20, 15},
        {30, 25},
        {8, 8},     // quadrado
        {12, 11},   // quase quadrado
        {50, 2},    // muito diferente de um quadrado
        {40, 30},
        {5, 4},
        {18, 17},
        {9, 6},
        {100, 80},
        {14, 13},
        {7, 5},
        {60, 60},   // quadrado
        {22, 20},
        {35, 34},   // quase quadrado
        {80, 10},
        {16, 15},
        {45, 40},
        {3, 2}
    };
    terrenosQuadrados(ter);
    maiorPerimetro(ter);
    TerrenoQuaseQuadrado(ter);
    TerrenoPiorQuadrado(ter);

    return 0;
}
