#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE* cad1 = fopen("caderno.txt", "r");
    FILE* cad2 = fopen("caderno2.txt", "r");
    FILE* m = fopen("mescla.txt", "w");

    char charA, charB;

    while((charA = fgetc(cad1)) != EOF && (charB = fgetc(cad2)) != EOF){
        fprintf(m, "%c", charA);
        fprintf(m, "%c", charB);
    }
    
    if (charA != EOF ){
        fprintf(m, "%c", charA);
    }

    fclose(cad1);
    fclose(cad2);
    fclose(m);
}

