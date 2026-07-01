#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE* fp = fopen("caderno.txt", "r");

    int letras[20] = {};
    char palavra[50];
    while(fscanf(fp, "%49s\n", palavra ) == 1){
        int len = strlen(palavra);
        if (len > 20) continue;
        letras[len - 1]++;
    }

    fclose(fp);

    for (int i = 0 ; i < 20; i++){
        printf("%d palavras de %d letras\n", letras[i], i+ 1);
    }

}