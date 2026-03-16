#include <stdio.h>

int main ()
{
    float prato, sob, total;
    int val_liv = 48, val_kilo = 84;
    printf("Coloque o peso do prato e da sobremesa - ");
    scanf("%f %f", &prato, &sob);

    total = (prato + sob)* val_kilo;

    if (total> val_liv)
        printf("Pagar livre - R$48,00");
    else 
        printf("Pagar Kilo - total R$%.2f", total);
}