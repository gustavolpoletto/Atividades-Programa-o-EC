#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int matriz[80][24];

void printMatriz(){
    for (int i = 0 ; i < 80 ; i++){
        for (int j = 0 ; j < 24 ; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    } 
}
void zerarMatriz(){
    for (int i = 0 ; i < 80 ; i++){
        for (int j = 0 ; j < 24 ; j++){
            matriz[i][j] = 0;
        }
    } 
}

int posSem[5][2];
void randPos(){
    srand(time(NULL));
    for (int i = 0 ; i < 5 ; i++){
            posSem[i][0] = rand() % 80;
            posSem[i][1] = rand() % 24;
    }
}


int max(int a, int b){
    if ( a < 0) a = -a;
    if ( b < 0) b = -b;

    if ( a > b) return a;
    return b;
}

int minPos ( int* dis ){
    int min = dis[0], p = 0;
    for (int i = 0; i < 5; i++){
        if (dis[i] == 0) return -1;
        if (dis[i] < min){
            min = dis[i];
            p = i;
        }
    }
    return p;
}


char findClosest(int i , int j){
    int dis[5];
    dis[0] = max(i - posSem[0][0] , j - posSem[0][1]);
    dis[1] = max(i - posSem[1][0] , j - posSem[1][1]);
    dis[2] = max(i - posSem[2][0] , j - posSem[2][1]);
    dis[3] = max(i - posSem[3][0] , j - posSem[3][1]);
    dis[4] = max(i - posSem[4][0] , j - posSem[4][1]);

    int n = minPos (dis);
    if (n == -1) return 'X';
    if (n == 0) return '*';
    if (n == 1) return '`';
    if (n == 2) return '~';
    if (n == 3) return '-';
    if (n == 4) return '^';
    return ' ';
    

}

void fillTable() {
    for (int i = 0 ; i < 80 ; i++){
        for (int j = 0 ; j < 24 ; j++){
            matriz[i][j] = findClosest(i, j);
        }
    } 
}

void printSementes(){
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 2 ; j++){
            printf("%2d ",posSem[i][j]);
        }
        printf("\n");
    }
}

int main(){
    zerarMatriz();
    randPos();
    fillTable();
    printSementes();
    printMatriz();
}