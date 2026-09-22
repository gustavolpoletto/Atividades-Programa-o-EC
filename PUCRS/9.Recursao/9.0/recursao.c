#include <stdio.h>

int soma (int i , int j){
    if (j < i) return 0;
    if (j == i) return i;
    return i + soma(i + 1 , j - 1) + j;
}

int main()
{
    int a, b;
    printf("- ");
    scanf("%d %d", &a, &b);
    
    printf("soma de %d a %d = %d\n" , a, b, soma(a , b));

    return 0;
}