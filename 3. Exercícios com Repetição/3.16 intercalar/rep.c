#include <stdio.h>

int main ()
{
   int a, b, s, i = 1000;

   printf("Entre os numeros a e b - ");
   scanf("%i %i", &a, &b);

   while(i > 0)
   {
      s = a % i;
      a = a / i;
      a = a * i * 10 + s;
      i = i / 10;
   } 
   i = 1000;
   while(i > 1)
   {
      s = b % i;
      b = b / i;
      b = b * i * 10 + s;
      i = i / 10;
   } 

   printf("%i\n", a + b);
   

}