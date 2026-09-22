#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE* fp = fopen("caderno.txt", "r");

    int num, max = INT_MIN, rep = 0;
    while(fscanf(fp, "%d\n", &num ) == 1){
        if (num > max){
            max = num;
            rep = 1;
        }
        else if(num == max) rep++;
    }

    fclose(fp);

    printf("o maior numero e %d e aparece %d vezes", max, rep);
}