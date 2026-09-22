#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE* cad1 = fopen("caderno.txt", "w");
    FILE* cad2 = fopen("caderno2.txt", "w");
    FILE* m = fopen("mescla.txt", "r");

    char c;
    int arq = 0;

    while((c = fgetc(m)) != EOF){
        if (arq == 0){
            fprintf(cad1, "%c", c);
            arq = 1;
        }
        else{
            fprintf(cad2, "%c", c);
            arq = 0;
        }
    }

    fclose(cad1);
    fclose(cad2);
    fclose(m);
}

