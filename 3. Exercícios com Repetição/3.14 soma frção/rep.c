#include <stdio.h>

int main ()
{
   float s1, s2, s3, sum = 0;
   int n;
   for ( int i = 0 ; i < 30; i++)
   {
      if (i == 10) s1 = sum;
      if (i == 20) s2 = sum;
      n = 1;
      for( int j = 0;  j < i; j++)
      {
         n *= 2;
      }
      sum += 1.0/n;
   }

   s3 = sum;
   printf("soma 10 termos = %.2f\nsoma 20 termos = %.2f\nsoma 30 termos = %.2f\n", s1, s2, s3);
}