#include <stdio.h>

void printPanquecas (int* pan, int s, int e){
        for (int i = 0; i < e; i++){
            printf("%d ", pan[i]);
        }
        printf("\n");
}

void virar(int*pan , int l, int r){
    while(l < r){
        int temp = pan[l];
        pan[l] = pan[r];
        pan[r] = temp;
        l++; r--;
    }
}

void main(){
    int tam;
    printf("entre o tamanho: ");
    scanf("%d", &tam);
    
    int pan[tam];
    for (int s = 0; s < tam ; s++){
        printf("Panqueca %d: ", s + 1);
        scanf("%d", &pan[s]);
    }

    for (int i = 0; i < tam; i++){
        printf("%d ", pan[i]);
    }
    printf("\n");
    int viradas = 0;

    
    for (int i = 0; i < tam - 1 ; i++){
        
        int mai = pan[i], pos = i;

        for (int j = i + 1; j < tam; j++){
            if (pan[j] > mai) {mai = pan[j]; pos = j;}
        }

        // já esta no lugar
        if (pos == i) continue;

        int l = pos, r = tam - 1, temp;
        
        // esta na ultima posição - não precisa da primeira virada
        if(pos != tam - 1){
            virar(pan, l, r);
            viradas++;
            
            // printPanquecas(pan, 0, tam);
        }
        
        // coloca na posição certa
        l = i; r = tam - 1;
        
        virar(pan, l, r);
        viradas++;

        // printPanquecas(pan, 0, tam);
    }

    printf("\nviradas = %d\n", viradas);

}