#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int board[4][4];

void zerarTabuleiro(){
    for (int i = 0 ; i < 4; i ++){
        for ( int j = 0 ; j < 4 ; j++){
            board[i][j] = 0;
        }
    }
}

void printTabuleiro(){
    for (int i = 0 ; i < 4; i ++){
        for ( int j = 0 ; j < 4 ; j++){
            printf("%4d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool podeJogar(){
    for (int i = 0 ; i < 4; i ++){
        for ( int j = 0 ; j < 4 ; j++){
            if(board[i][j] == 0) return true;
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (j + 1 < 4 && board[i][j] == board[i][j+1]) return true;
            if (i + 1 < 4 && board[i][j] == board[i+1][j]) return true;
        }
    }
    return false;
}

void criar2(){
    int x = rand() % 4, y = rand() % 4;
    while(board[x][y] != 0){
        x = rand() % 4;
        y = rand() % 4;
    }

    board[x][y] = 2;
}


void jogarDireita(){
    for (int i = 0; i < 4; i++){
        bool merged[4] = {false, false, false, false};
 
        for (int j = 2; j >= 0; j--){
            if(board[i][j] == 0) continue;

            int pos = j;
            while(pos + 1 < 4 && board[i][pos + 1] == 0){
                board[i][pos + 1] = board[i][pos];
                board[i][pos] = 0;
                pos++;
            }

            if(pos + 1 < 4 && board[i][pos] == board[i][pos + 1] && !merged[pos + 1]){
                board[i][pos] = 0;
                board[i][pos + 1] *= 2;
                merged[pos + 1] = true;
            }
        }
    }
}
 
void jogarEsquerda(){
    for (int i = 0; i < 4; i++){
        bool merged[4] = {false, false, false, false};
 
        for (int j = 1; j < 4; j++){
            if(board[i][j] == 0) continue;

            int pos = j;
            while(pos - 1 >= 0 && board[i][pos - 1] == 0){
                board[i][pos - 1] = board[i][pos];
                board[i][pos] = 0;
                pos--;
            }

            if(pos - 1 >= 0 && board[i][pos] == board[i][pos - 1] && !merged[pos - 1]){
                board[i][pos] = 0;
                board[i][pos - 1] *= 2;
                merged[pos - 1] = true;
            }
        }
    }
}
 
void jogarCima(){
    for (int j = 0; j < 4; j++){
        bool merged[4] = {false, false, false, false};
 
        for (int i = 1; i < 4; i++){
            if(board[i][j] == 0) continue;
 
            int pos = i;
            while(pos - 1 >= 0 && board[pos - 1][j] == 0){
                board[pos - 1][j] = board[pos][j];
                board[pos][j] = 0;
                pos--;
            }

            if(pos - 1 >= 0 && board[pos][j] == board[pos - 1][j] && !merged[pos - 1]){
                board[pos][j] = 0;
                board[pos - 1][j] *= 2;
                merged[pos - 1] = true;
            }
        }
    }
}
 
void jogarBaixo(){
    for (int j = 0; j < 4; j++){
        bool merged[4] = {false, false, false, false};
 
        for (int i = 2; i >= 0; i--){
            if(board[i][j] == 0) continue;

            int pos = i;
            while(pos + 1 < 4 && board[pos + 1][j] == 0){
                board[pos + 1][j] = board[pos][j];
                board[pos][j] = 0;
                pos++;
            }
 
            if(pos + 1 < 4 && board[pos][j] == board[pos + 1][j] && !merged[pos + 1]){
                board[pos][j] = 0;
                board[pos + 1][j] *= 2;
                merged[pos + 1] = true;
            }
        }
    }
}

void jogada(){
    char j;
    while(true){
        printf("movimento (wasd) -");
        scanf(" %c", &j);

        if      (j == 'w') {jogarCima();     return;}
        else if (j == 'a') {jogarEsquerda(); return;}
        else if (j == 's') {jogarBaixo();    return;}
        else if (j == 'd') {jogarDireita();  return;}
    }

}


int main(){
    srand(time(NULL));
    zerarTabuleiro();
    
    criar2();
    criar2();

    while(podeJogar()){
        printTabuleiro();
        jogada();
        system("cls");
        criar2();
    }
    
    printTabuleiro();
    printf("GAME OVER\n");
}