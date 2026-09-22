#include <stdio.h>

int main ()
{
   int a, i=0, f = 1, n;

    printf("Entre a - ");
    scanf("%i", &a);

   int t = a;
    while( t > 0 )
    {
        i++;
        t = t /10;
    }
    
    for (int j = 0; j < i/3 ; j++)
    {
       f = 1000 * f;
    }
    printf("%i\n", f);

    while(f > 0)
    {
      n = a % (f * 1000);
      printf("%i", n/f);
      if (f > 1)printf(".");
      f /=1000;
    }
    printf("\n");
}