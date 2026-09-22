#include <stdio.h>

int matriz[15][15];

void printMatriz(){
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            if (matriz[i][j] == 0) printf("   ");
            else printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    } 
}

int main(){
    for (int i = 0 ; i < 15 ; i++){
        for (int j = 0 ; j < 15 ; j++){
            matriz[i][j] = i + j;
        }

    } 
    printMatriz();
}