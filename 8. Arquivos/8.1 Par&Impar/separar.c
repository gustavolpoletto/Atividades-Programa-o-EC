#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE* fp = fopen("caderno.txt", "r");
    FILE* par = fopen("par.txt", "w");
    FILE* impar = fopen("impar.txt", "w");

    int num;
    while(fscanf(fp, "%d\n", &num ) == 1){
        if (num % 2 == 0) fprintf(par, "%d\n", num);
        else fprintf(impar, "%d\n", num);
    }

    fclose(fp);
    fclose(par);
    fclose(impar);
}