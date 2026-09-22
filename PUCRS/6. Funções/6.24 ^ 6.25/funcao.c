#include <stdio.h>
#include <stdbool.h>

int divCount(int a) {
    int r = 0;
    for (int i = 1; i <= a ; i++){
        if((a % i) == 0) r++;
    }
    return r;
}

bool ehPrimo (int a){
    if (divCount(a) == 2) return true;
    return false;
}

int proxPrimo (int a){
    a += 1;
    if(ehPrimo(a)) return a;
    proxPrimo(a + 1);
}

int main(){
    int a;
    printf("- ");
    scanf("%d", &a);

    printf("%d tem %d divisores\n", a, divCount(a));
    if (ehPrimo(a)) printf("eh primo\n");
    else        printf("num eh primo\n");

    printf("Proximo primo = %d", proxPrimo(a));
}