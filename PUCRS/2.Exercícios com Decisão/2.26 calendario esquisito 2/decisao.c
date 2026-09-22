#include <stdio.h>

int main ()
{
    int d, m, h, min, s, tempo, dias = 0;
    int d2, m2, h2, min2;

    printf("Entre o dia, mes, hora, minuto e segundo - ");
    scanf("%i %i %i %i %i", &d, &m, &h, &min, &s);

    switch (m){
        case 12: dias += 30;    
        case 11: dias += 31; 
        case 10: dias += 30;    
        case 9 : dias += 31;      
        case 8 : dias += 31; 
        case 7 : dias += 30;    
        case 6 : dias += 31;
        case 5 : dias += 30;  
        case 4 : dias += 31;    
        case 3 : dias += 28;   
        case 2 : dias += 31; 
    }
    dias += (d - 1);

    tempo = (dias*86400 + h*3600 + min*60 + s) / 0.864;
    
    m2 = tempo / 3000000 + 1;
    tempo = tempo % 3000000;
    
    d2 = tempo / 100000 + 1;
    tempo = tempo % 100000;
    
    h2 = tempo / 10000;
    tempo = tempo % 10000;
    
    min2 = tempo / 100;
    tempo = tempo % 100;

    if (m2 == 13) printf(" dia especial %i, %ih %im %is", d2, h2, min2, tempo);
    else          printf("%i/%i , %ih %im %is", d2, m2, h2, min2, tempo);
}