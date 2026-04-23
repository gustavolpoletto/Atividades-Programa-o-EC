#include <stdio.h>

int main ()
{
    int d, c, a;
    float b, final;

    printf("---Calculo do Salario do Funcionario---\n");

    printf("Entre o salario base - R$");
    scanf("%f", &b);

    printf("Entre o numero de dependentes - ");
    scanf("%d", &d);

    printf("Entre os anos de casa - ");
    scanf("%d", &c);

    printf("Entre o ano atual - ");
    scanf("%d", &a);

    final = b;

    if(d <= 6)
        final = final + (0.04 * b * d);
    else
        final = final + (0.04 * b * 6);

     int acrecimos = 0;

     if (d < 3)
     {
        acrecimos = c / 5;
        if (acrecimos > 5) acrecimos = 5;
        final = final + (b * 0.03 * acrecimos);
     }

    else 
     {
        acrecimos = c / 6;
        if (acrecimos > 7) acrecimos = 7;
        final = final + (b * 0.04 * acrecimos);
     }


    int bi = 0;

    if (a % 4 == 0)
        {
            if (a  % 100 == 0)
            {
                if (a % 400 == 0)
                    bi = 1;
            }
            else
                bi = 1;
        }

    if (bi == 1) final = final + (b*0.01);

    printf("\n      -    Salario final = R$%.2f\n", final);

}