#include <stdio.h>

 int main()
 {
     int a , c = 0;
     float b = 0;
     printf("Entre a - ");
     scanf("%i", &a);
    
     while (a != 0)
     {
         b = b / 10;
         b = b + a % 2;
         a = a /2;
         c++;
     }
     int d = 1;
     for(int i = 1; i < c; i++)
     {
         d *= 10;
     }
     printf("Bin -> %.0f\n", b*d);
     return 0;
 }