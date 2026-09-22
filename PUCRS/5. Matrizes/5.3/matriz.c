#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char matriz[24][80];

void printMatriz(){
    for (int i = 0 ; i < 24 ; i++){
        for (int j = 0 ; j < 80 ; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    } 
}
void zerarMatriz(){
    for (int i = 0 ; i < 24 ; i++){
        for (int j = 0 ; j < 80 ; j++){
            matriz[i][j] = '-';
        }
    } 
}

int sementes[200][2];
void gerarSementes(){
    srand(time(NULL));
    for (int i = 0 ; i < 200 ; i++){
            sementes[i][0] = rand() % 24;
            sementes[i][1] = rand() % 80;
    }
}

void plantarSementes(){
    for (int i = 0 ; i < 200 ; i++){
        matriz[sementes[i][0]][sementes[i][1]] = 'X';
    }
}

void ploriferar(){
    for (int i = 0 ; i < 24 ; i++){
        for (int j = 0 ; j < 80 ; j++){
            
            int count = 0;
            for (int a = -1 ; a <= 1 ; a++){
                for (int b = -1 ; b <= 1 ; b++){
                    int x = i + a, y = j + b;
                    if (x < 0 || x > 24) continue;
                    if (y < 0 || y > 80) continue;
                    
                    if(matriz[x][y] == 'X') count++;

                    if (count == 3) matriz[i][j] = 'X';
                    else matriz[i][j] = '-';

                }
            }

        }
    } 
}

int main(){
    zerarMatriz();
    gerarSementes();
    plantarSementes();
    printMatriz();
    
    for (int i = 0 ; i < 5 ; i++){
        printf("\n\n");
        ploriferar();
        printMatriz();
    }
}