#include <stdio.h>

int mistery( int a, int b ) {
int r = 0;
while ( b > 0 ) {
r += (b % 2) * a;
b /= 2;
a *= 2;
}
return r;
}

int main(){
    int a, b;
    printf("- ");
    scanf("%d %d", &a, &b);

    printf("%d %d - %d\n", a, b, mistery(a, b));

}