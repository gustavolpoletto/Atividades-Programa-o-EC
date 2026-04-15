#include <stdio.h>

int main()
{
    float n,  a, r = 0, b = 1;
    int f = 1, ap;
    printf("Entre N - ");
    scanf("%f", &n);
    printf("Entre a proximação - ");
    scanf("%i", &ap);
    for(int i = 0; i < ap; i++)
    {
        b = b / 10;
    }
    printf("\nb = %f\n", b);
    while(n > b)
    {
         printf("\nn = %f\n", n);
        f = f*2;
        a = 1.0/f;
        if( a <= n )
        {
            n = n - a;
            printf("1/%i ", f);
            r += a;
        }
    }
    printf("\n%f\n", r);
    
}