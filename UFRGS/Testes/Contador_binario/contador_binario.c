// COntador em binario (invertido) para programa em arduino

#include <stdio.h>

int main(){
    for (int i = 0 ; i < 16; i++){
        int v = i;
        printf("%2d -> ", v);
        
        for (int j = 0; j < 4; j++){
            printf("%d ", v % 2);
            v = v >> 1;

        }
             
        printf("\n");

    }
}