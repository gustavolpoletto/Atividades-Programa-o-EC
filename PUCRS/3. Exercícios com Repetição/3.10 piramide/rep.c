#include <stdio.h>

int main ()
{
    int a, soma = 0, slin = 0;
ntf("Entre o numero- ");
    scanf("%
    prii", &a);

    for (int i = 1; i < a + 1; i++)
    {
        for(int j = 0; j < i; j++)
        {
            soma+=i;
            slin+= i;
            printf("%2i ", i);
        }
        printf("\n");
        // printf("soma da linha = %i\n", slin);
        slin = 0;
    }

    printf("soma de todos => %i\n", soma);

}