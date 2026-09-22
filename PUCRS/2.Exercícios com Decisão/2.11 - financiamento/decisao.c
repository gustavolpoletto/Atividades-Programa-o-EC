#include <stdio.h>

int main ()
{
    float divida;

    printf("qual a divida? - ");
    scanf("%f", &divida);

    float entrada = divida * 0.1;
    printf("entrada - %.2f\n", entrada);

    if (entrada > 1000)
    {
        divida = divida - 1000;
        printf("entrada - R$1000\n");
    }
    else {
        divida = divida - entrada;
        printf("entrada - %.2f\n", entrada);
    }

    int parcelas = divida / 200;

    if (parcelas > 72)
    {
        float valor = divida / 72.0;
        printf("72 parcelas de R$%.2f\n", valor);
    }
    else{
        printf("%i parcelas de R$%i\n", parcelas , 200);
        if ((divida - parcelas * 200) > 0)
        printf("ultima parcela de R$%.2f\n" , divida - parcelas * 200);
    }
  
}