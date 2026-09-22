#include <stdio.h>

 int main()
 {
     int a , b, x = 0;
    
     printf("Entre a e b - ");
     scanf("%i %i", &a, &b);
    
     while (a!= 0)
     {
     if(a % 2 != 0) x += b;
     b = b*2;
     a = a/2;
     }
   
     printf("- %i\n", x);
     return 0;
 }