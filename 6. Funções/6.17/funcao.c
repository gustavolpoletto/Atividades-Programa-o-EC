#include <stdio.h>

#define LIN 20
#define COL 50
char matriz[LIN][COL];

void init_matriz(){

    for (int i = 0 ; i < LIN ; i++){
        for (int j = 0 ; j < COL ; j++){
            matriz[i][j] = '.';
        }
    }
}

void print_matriz(){
    for (int i = 0 ; i < LIN ; i++){
        for (int j = 0 ; j < COL ; j++){
            printf("%c " ,matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void reserva_casal(){
    for (int i = 0 ; i < LIN ; i++){
        for (int j = 0 ; j < COL - 1 ; j++){
            if (matriz[i][j] == '.' && matriz[i][j + 1] == '.'){
                printf("Foram reservados os assentos %d %d e %d %d\n", i, j, i, j+1);
                matriz[i][j] = matriz[i][j + 1] = 'R';
                return;
            }
        }
    } 
}

void reserva_bloco(int l, int c){
    for (int i = 0 ; i <= LIN - l ; i++){
        for (int j = 0 ; j <= COL - c ; j++){
            int flag = 0;
            for (int k = i ; k < i + l ; k++){
                for (int l = j ; l < j + c ; l++){
                    if (matriz[k][l] != '.') {flag = 1; break;}
                }
                if (flag == 1) break;
            }

            if (flag == 0){
                for (int k = i ; k < i + l ; k++){
                    for (int l = j ; l < j + c ; l++){
                        matriz[k][l] = 'C';
                    }
                }
                return;
            }


        }     
    }
    printf("Não há espaço diponível\n");
}
     
int main(){
    init_matriz();
    print_matriz();
    
    char choice = 'c';
    while (choice != 'S'){
        printf("Gostaria de Comprar (C), Reservar (R), Desreservar (D) o ingresso, Comprar casal (M) ou Comprar bloco (B)? Sair (S)\n- ");
        scanf(" %c", &choice);
        if (choice != 'C' && choice != 'R' && choice != 'D' && choice != 'M' && choice != 'B') continue;

        if (choice == 'M'){
            reserva_casal();
            print_matriz();
        }
        
        else if (choice == 'B'){
            printf("Quantos lugares necessita (linhas colunas)?\n- ");

            int l, c;
            scanf("%d %d", &l, &c);

            reserva_bloco(l, c);
            print_matriz();
        }

        else{
            printf("Qual lugar deseja (linha coluna)?\n- ");
            int lin, col;
            scanf("%d %d", &lin, &col);

            if (lin < 0 || lin >= LIN || col < 0 || col >= COL){
                printf("Posicao invalida\n");
                continue;
            }

            if (choice == 'D'){
                if (matriz[lin][col] == 'R') matriz[lin][col] = '.';
                else printf("Lugar não estava reservado\n");

                print_matriz();
                continue;
            }

            if (matriz[lin][col] == '.') matriz[lin][col] = choice;
            else printf("Cadeira já ocupada\n");
            print_matriz();
        } 
        
    }

}