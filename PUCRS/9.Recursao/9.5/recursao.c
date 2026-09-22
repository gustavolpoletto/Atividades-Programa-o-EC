#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

int matriz[SIZE][SIZE];

void initmatriz(){
    int idx = 0;
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            matriz[i][j] = idx++;
        }
    }
}
void printmatriz(){
    for (int i = 0 ; i < SIZE ; i++){
        for (int j = 0 ; j < SIZE ; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void troca(int r, int c, int sc , int sr){
    
    if (r <= 1 || c <= 1) return;
    
    for (int i = sc ; i < c + sc ; i++){
        for (int j = sr ; j < sr + r ; j++){
            int temp = matriz[i + sc][j + sr];
            matriz[i + sc][j + sr] = matriz[sc + i][sr + j];
            matriz[sc + i][sr + j] = temp;
        }
    }
    troca(r / 2 , c / 2, sc , sr);
    troca(r / 2 , c / 2, sc + r / 2 , sr);
    troca(r / 2 , c / 2, sc , sr + r / 2);
    troca(r / 2 , c / 2, sc + r / 2 , sr + r / 2);
}

int main()
{
    initmatriz();
    printmatriz();
    troca(SIZE, SIZE, 0, 0);
    printmatriz();
}