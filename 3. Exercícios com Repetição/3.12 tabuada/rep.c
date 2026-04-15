#include <stdio.h>

int main ()
{
    for (int i = 1; i<= 10; i++)
    {
        printf("- Tabuada do %i\n", i);
        for (int j = 1; j <= 10; j++)
        {
            printf("%i * %i = %i\n", i, j, i*j);
        }
        printf("\n");
    }

}