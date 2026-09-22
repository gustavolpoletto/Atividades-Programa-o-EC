#include <stdio.h>

 int main()
 {
     int n;
    
     printf("Entre N - ");
     scanf("%i", &n);
    
     int s = 1, r = 0;
     for (int i = 0; i < n; i++)
     {
         s += i;
     }
     for (int j = 0; j < n; j++)
     {
         r = r + s + j;
     }
     printf("%i\n", r);
 }
