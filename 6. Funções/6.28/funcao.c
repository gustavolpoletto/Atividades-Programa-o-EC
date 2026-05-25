#include <stdio.h>


int fat(int a){
    if (a == 0) return 1;
    int r = a--;
    while( a > 0){
        r*= a--;
    }
    return r;
}

int pot( int a, int b ) {
    int r = 1, flag = 0;
    for (int i = 0 ; i < b ; i++){
        r*= a;
    }
    return r;
}


float co(int a, int pres){
    float r = 1.0;
    int idx = 2, flag = 0;
    for (int i = 0 ; i < pres ; i++){
        if (flag == 0){
            r-= 1.0 *  pot(a, idx) / fat(idx);
            flag = 1;
        }
        else{
            r+= 1.0 *  pot(a, idx) / fat(idx);
            flag = 0;           
        }
        idx*= 2;
    }
    return r;
}

int main(){
    int a, p;
    printf("Entre angulo(rad) e precisao- ");
    scanf("%d %d", &a, &p);

    printf("cos(%d) = %.2f\n", a, co(a, p));
}