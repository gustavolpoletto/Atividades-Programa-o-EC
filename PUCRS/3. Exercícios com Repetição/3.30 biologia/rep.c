#include <stdio.h>

int main()
{
    long long int vida[5] = {0};
    double peso = 1, lixo = 0;
    for (int i = 0; i < 12; i++){
        peso = peso/10;
    }
    vida[4] = 5;
    printf("peso bacteria = %.15f\n", peso);

    for (int dia = 1; dia <= 60; dia++)
    {
        lixo = lixo + (peso/2 * vida[0] + peso/2 * vida[1] + peso/2 * vida[2] + peso/2 * vida[3] + peso/2 * vida[4]);
        printf("Dia %li -> Bacterias = %lli -> consumido %.15f\n", dia, vida[0]+vida[1]+vida[2]+vida[3]+vida[4], lixo);
        vida[0] = vida[1];
        vida[1] = vida[2];
        vida[2] = vida[3];
        vida[3] = vida[4];

        vida[4] = vida[0] +vida[1] +vida[2] +vida[3];
        
    }
    int dec = 0;
    if (lixo > 0)
    {
        while (lixo > 9)
        {
            lixo = lixo / 10;
            dec++;
        }
        
    }
    else{
        while (lixo , 0)
        {
            lixo = lixo * 10;
            dec--;
        }
    }
    int decimal= 1;
    if(dec >= 3 && dec < 6)
    {
        for (int i = 0; i < dec - 3; i++) decimal = decimal * 10;
        printf("%fKg de lixo\n", lixo * decimal);
    }
    if(dec >= 6 && dec < 9)
    {
        for (int i = 0; i < dec - 6; i++) decimal = decimal * 10;
        printf("%fTon de lixo\n", lixo * decimal);
    }

}