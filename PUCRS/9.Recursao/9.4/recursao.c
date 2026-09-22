#include <stdio.h>
#include <stdbool.h>


bool ehprimo (int a){
    for (int i = 2 ; i < a; i++){ if (a % i == 0) return false; }
    return true;
}

int proxprimo ( int a ){
    if (a < 2) return 2;
    a++;
    while (true) {
        int flag = 0;
        for (int i = 2 ; i < a; i++){ if (a % i == 0) flag = 1; }
        if (flag == 0) return a;
        a++;
        
    }
}

void somaprimo(int a, int p1, int p2, int* end){
    if (a < p1 + p2) return;
    if (a == p1 + p2)  *end = p1;
    somaprimo(a , proxprimo(p1), p2, end);
    somaprimo(a , p1, proxprimo(p2), end);
    somaprimo(a , proxprimo(p1), proxprimo(p2), end);
}

int main()
{
    int a, p1 = 2, p2 = 2 , r;
    printf("- ");
    scanf("%d", &a);
    if (a % 2 != 0 || a == 2){
        printf("inserir apenas pares diferentes de 2\n");
        return 1;
    }
    
    somaprimo(a , p1, p2, &r);
    p1 = r;
    p2 = a - p1;
    
    printf("%d = %d + %d\n" , a, p1, p2);

    return 0;
}