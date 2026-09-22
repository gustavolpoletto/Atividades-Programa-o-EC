#include <stdio.h>

int invert( int a ) {
int r = 0;
while ( a > 0 ) {
 r *= 10;
 r+= a % 10;
 a /= 10;
}
return r;
}

int main(){
    int a;
    printf("- ");
    scanf("%d", &a);

    printf("%d - %d\n", a, invert(a));

}
