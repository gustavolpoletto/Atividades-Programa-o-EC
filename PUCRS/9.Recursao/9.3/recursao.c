#include <stdio.h>

int fatorial (int a){
    if (a == 0) return 1;
    return a * fatorial(a - 1);
}

int main()
{
    int a;
    printf("- ");
    scanf("%d", &a);
    
    printf("fatorial de %d = %d\n" , a, fatorial(a));

    return 0;
}