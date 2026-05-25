#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* copy(char* a){
    int sizeA = strlen(a);
    printf("%d\n", sizeA);
    char* c = malloc(sizeof(char) * sizeA);
    for (int i = 0; i < sizeA; i++){
        c[i] = a[i];
    }
    c[sizeA] =  '\0';
    return c;
}

int main(){
    char a[] = "Ola Mundo!!!";
    char* cpy = copy(a);
    printf("original -> %s\n   copia -> %s\n", a, cpy);

}