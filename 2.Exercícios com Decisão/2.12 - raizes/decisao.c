#include <stdio.h>
#include <math.h>

int main ()
{
    int a, b, c; 
    float r1, r2;
    printf ("determine os valores de a, b e c - ");
    scanf("%i %i %i", &a, &b, &c);

    r1 = (sqrt(b * b - (4 * a * c)) - b) / 2 * a;
    r2 = (0 - sqrt(b * b - (4 * a * c)) - b) / 2 * a;

    printf("raizes = %f %f\n", r1, r2);
}
  
