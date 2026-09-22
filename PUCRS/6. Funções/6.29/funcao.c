#include <stdio.h>
#include <stdbool.h>


bool ehPrimo (int a){
    for (int i = 2; i < a ; i++){
        if((a % i) == 0) return false;
    }
    return true;
}

void primoGemeo(){
    int a = 2;
    while (true){
    if (ehPrimo(a) && ehPrimo(a + 2)){
        printf("%d e %d\n", a, a + 2);
    }
    a++;
    }
}

int main(){
    primoGemeo();
}