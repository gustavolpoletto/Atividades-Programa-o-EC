#include <stdio.h>

 int main()
 {
     int a, b, c;
     int f;
    
     printf("Entre os valores das moedas - ");
     scanf("%i %i %i", &a, &b, &c);
    
     for (int t = 0; t <= 100; t++){
         f = 0;
         for (int x = 0; x <= 100; x++){
             for (int y = 0; y <= 100; y++){
                 for (int z = 0; z <= 100; z++){
                     if(a*x + b*y  + c*z == t)
                     {
                         f = 1;
                         break;
                     }
                 if (f == 1) break;
                 }
             if (f == 1) break;
             }
         if (f == 1) break;
         }
         if (f == 0) printf("não funciona em %i\n", t);
     }
 }
