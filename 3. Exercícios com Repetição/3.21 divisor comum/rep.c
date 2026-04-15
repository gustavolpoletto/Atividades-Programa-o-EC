#include <stdio.h>

 int main()
 {
     int a, b, tmp;
     printf("Entre a e b - ");
     scanf("%i %i", &a, &b);
    
     while(b!= 0)
     {
         tmp = a;
         a = b;
         b = tmp % b;
     }
     printf("maior divisor comum => %i\n", a);

     return 0;
 }