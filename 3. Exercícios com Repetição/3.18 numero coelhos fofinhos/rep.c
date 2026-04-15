#include <stdio.h>

int main ()
{
   int d, n= 0, u = 1, p= 1;
   

   printf("Entre os dias - ");
   scanf("%i", &d);

   for(int i = 1; i <= d; i++)
   {
      n+= p;
      p = u;
      u = n;
   }

   printf("%i Coelhos", n);


}