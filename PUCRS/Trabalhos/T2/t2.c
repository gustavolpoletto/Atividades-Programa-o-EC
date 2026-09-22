#include <stdio.h>

void main(){
    int tam;
    printf("entre o tamanho: ");
    scanf("%d", &tam);
    
    int pan[tam];
    for (int s = 0; s < tam ; s++){
        printf("Panqueca %d: ", s + 1);
        scanf("%d", &pan[s]);
    }

    // for (int i = 0; i < tam; i++){
    //     printf("%d ", pan[i]);
    // }
    // printf("\n");
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
            while(l < r){
                temp = pan[l];
                pan[l] = pan[r];
                pan[r] = temp;
                l++; r--;
            }
            viradas++;

            // for (int p = 0; p < tam; p++){
            //     printf("%d ", pan[p]);
            // }
            // printf("\n");
        }
        
        // coloca na posição certa
        l = i; r = tam - 1;
        while(l < r){
            temp = pan[l];
            pan[l] = pan[r];
            pan[r] = temp;
            l++; r--;
  
        }
        viradas ++;

        // for (int p = 0; p < tam; p++){
        //     printf("%d ", pan[p]);
        // }
        // printf("\n");
    
    }

    printf("\nviradas = %d\n", viradas);

}