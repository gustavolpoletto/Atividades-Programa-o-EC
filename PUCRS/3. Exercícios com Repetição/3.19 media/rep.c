#include <stdio.h>

int main ()
{
   int count = 0, n, m=0;
   printf("|num|med|\n");
   while ( 1 )
   {
      printf("Entre um numero - ");
      scanf("%i", &n);

      count++;
      m = (m*(count-1) + n)/count;
      printf("| %i | %i |\n", n, m);
   }


}