#include <stdio.h>

int matriz[10][10];

void init_matriz(){
    int idx = 0;
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            matriz[i][j] = idx++;
        }
    }
}

void print_matriz(){
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            printf("%2d " ,matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transposicao(){
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < i ; j++){
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}


int main(){
    init_matriz();
    print_matriz();
    transposicao();
    print_matriz();
}