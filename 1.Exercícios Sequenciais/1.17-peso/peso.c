#include <stdio.h>
#include <stdbool.h>

void main ()
{
    float peso;
    int opcao;
    printf("Peso - ");
    scanf("%f", &peso);

    while(true){
        printf("\t-PLANETA\n[1]Mercurio\n[2]Venus\n[3]Marte\n[4]Terra\n[5]\n[6]Jupter\n[7]Saturno\n[8]Urano\n[9]Netuno\n[10]Plutao\n[outro]Sair\n - ");
        scanf("%i", &opcao);

       switch (opcao){
        case 1:
            printf("Peso em Mercurio => %.2f\n", peso*0.3649337410
);
            break;
        case 2:
            printf("Peso em Venus => %.2f\n", peso*0.9041794087);
            break;
        case 3:
            printf("Peso em Marte => %.2f\n", peso*0.3812436289);
            break;
        case 4:
            printf("Peso na Lua => %.2f\n", peso*0.1651376146);
            break;
        case 5:
            printf("Peso na Terra => %.2f\n", peso);
            break;
        case 6:
            printf("Peso em Jupter => %.2f\n", peso*2.6513761467);
            break;
        case 7:
            printf("Peso em Saturno => %.2f\n", peso*1.1386340468);
            break;
        case 8:
            printf("Peso em Urano => %.2f\n", peso*1.0693170234);
            break;
        case 9:
            printf("Peso em Netuno => %.2f\n", peso*1.3506625891);
            break;
        case 10:
            printf("Peso em Plutao => %.2f\n", peso*0.2252803261);
            break;

        default:
            return;
       }
    }
}

