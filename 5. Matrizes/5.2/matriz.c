#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int matriz[24][80];

void printMatriz(){
    for (int i = 0 ; i < 24 ; i++){
        for (int j = 0 ; j < 80 ; j++){
            printf("%2i ", matriz[i][j]);
        }
        printf("\n");
    } 
}
void zerarMatriz(){
    for (int i = 0 ; i < 24 ; i++){
        for (int j = 0 ; j < 80 ; j++){
            matriz[i][j] = 0;
        }
    } 
}
int form(int a){
    return 2 + 24 * (a - 40) * (a - 40)/2000;
}

void fillMatriz (){
    for (int j = 0; j < 80; j++){
        int a = rand()  % 24;
        matriz[a][j] = 0;
        for (int i = 0 ; i < 24; i++){
            if (i == a) continue;
            matriz[i][j] =  form(a);

        }
    } 
}


int main(){
    zerarMatriz();
    fillMatriz();
    printMatriz();
}