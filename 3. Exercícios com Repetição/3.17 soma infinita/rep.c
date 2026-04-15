#include <stdio.h>

int main ()
{
   int n;
   float sum = 0;

   printf("Entre n - ");
   scanf("%i", &n);

   for(int i = 1; i <= n; i++)
   {
      sum += 1.0/i;
   }

   printf("soma => %f", sum);

}