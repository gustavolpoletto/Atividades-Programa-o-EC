#include <stdio.h>

int sequencia(int n){
    int c = 0;
    while (n != 1){
        if (n % 2 == 0) n = n / 2;
        else n = 3 * n + 1;
        c++;
    }
    return c;
}
int main(){
    int r = 0, v = 0;
    for (int i = 0 ; i < 100000 ; i++)
    {
        int n = sequencia(i);
        if (n > r) {r = n; v = i;}
    }

    printf("%d - %d", v, r);
}