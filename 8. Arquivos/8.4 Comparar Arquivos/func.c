#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE* cad1 = fopen("caderno.txt", "r");
    FILE* cad2 = fopen("caderno2.txt", "r");

    char charA, charB;
    int linha = 1;

    while((charA = fgetc(cad1)) != EOF && (charB = fgetc(cad2)) != EOF){
        if (charA != charB){
            printf("Diferentes na linha %d, %c != %c", linha, charA, charB);
            return 1;
        }
        else if (charA == '\n') linha ++;
    }
    
    if (charA != EOF || charB != EOF){
        printf("Apenas um Arquivo chegou ao fim - iguais ate linha %d", linha);
        return 2;
    }

    fclose(cad1);
    fclose(cad2);

    printf("Sao Iguais = %d linhas", linha);


}