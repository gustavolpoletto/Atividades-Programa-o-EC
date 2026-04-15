#include <stdio.h>

int main ()
{
    int d, c, a;
    float b, final;

    // receber o salário base b , o número de dependentes d , o número de anos de casa c do funcionário e o a atual a.
    // variavel final para quardar o salário até então

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

    // funcionário recebe um acréscimo de 4% sobre o salário base para cada dependente que ele tem (máximo 6)
    if(d <= 6)
        final = final + (0.04 * b * d);
    else
        final = final + (0.04 * b * 6);

     // Se o funcionário tem menos de 3 dependentes, ele recebe um acréscimo de 3% sobre o salário base paracada 5 anos de casa que ele tem (até o máximo de 5 acréscimos).
     int acrecimos = 0;

     if (d < 3)
     {
        acrecimos = c / 5;
        if (acrecimos > 5) acrecimos = 5;
        final = final + (b * 0.03 * acrecimos);
     }

     // Se o funcionário tem 3 ou mais dependentes ele recebe um acréscimo de 4% sobre o salário base para cada 6 anos de casa que ele tem (até o máximo de 7 acréscimos).
    else 
     {
        acrecimos = c / 6;
        if (acrecimos > 7) acrecimos = 7;
        final = final + (b * 0.04 * acrecimos);
     }

     // Todos ganham 1% extra de aumento sobre o salário base se for um a bissexto.

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

    printf("\nSalário final = R$%.2f\n", final);

}