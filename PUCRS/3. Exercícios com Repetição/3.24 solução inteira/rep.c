#include <stdio.h>

 int main()
 {
     for (int x = 0; x <= 100; x++){
         for (int y = 0; y <= 100; y++){
             for (int z = 0; z <= 100; z++){
                 if(3*x + 2*y - 7*z == 5)printf("X=%i , Y=%i , Z=%i\n", x, y, z);
             }
         }
     }
   
    
     return 0;
 }