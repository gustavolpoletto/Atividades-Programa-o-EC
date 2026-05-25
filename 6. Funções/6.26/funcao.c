#include <stdio.h>

float sqr(int a){
    float k = 1.0;
    for (int i = 0; i < 12; i++)
    {
         k = (k + a/k)/2;
    }
    return k;
}

int main(){
    int a;
    printf("- ");
    scanf("%d", &a);

    printf("V%d = %.2f\n", a, sqr(a));

}