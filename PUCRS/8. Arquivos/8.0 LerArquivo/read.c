#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE* fp = fopen("caderno.txt", "r");

    int num;
    while(fscanf(fp, "%d\n", &num ) == 1){
        printf("%d\n", num);
    }

    fclose(fp);
}