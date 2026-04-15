#include <stdio.h>

 int main()
 {
     int n;
     float k = 1;
    
     printf("Entre N - ");
     scanf("%i", &n);
    
     for (int i = 0; i < 12; i++)
     {
         k = (2*k + n/(k*k))/3;
     }
    
     printf("sqrt %i = %.2f\n", n, k);
 }
