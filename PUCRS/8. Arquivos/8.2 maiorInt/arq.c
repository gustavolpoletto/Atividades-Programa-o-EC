#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE* fp = fopen("caderno.txt", "w");

    for(int i = 0 ; i < 100; i ++){
        fprintf(fp, "%d\n", i * i * 30 % 107);
    }

    fclose(fp);
}