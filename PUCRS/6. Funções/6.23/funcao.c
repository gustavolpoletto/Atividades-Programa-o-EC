#include <stdio.h>

float pot( int a, int b ) {
    int r = a, flag = 0;
    if (b == 0) return 1;
    if ( b < 0){flag = 1; b = -b;}
    for (int i = 1 ; i < b ; i++){
        r*= a;
    }
    if (flag = 1) return 1.0 / r;
    return r;
}

int main(){
    int a, b;
    printf("- ");
    scanf("%d %d", &a, &b);

    printf("%d ^ %d = %.2f\n", a, b, pot(a, b));

}