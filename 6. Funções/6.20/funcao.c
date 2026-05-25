#include <stdio.h>

int contagem1emBin(int a){
    int res = 0;
    while (a != 0){
        res += a % 2;
        a /= 2;
    }
    return res;
}
int main(){
    int n;
    printf("-");
    scanf("%d", &n);

    printf("sao %d um's\n", contagem1emBin(n));

}