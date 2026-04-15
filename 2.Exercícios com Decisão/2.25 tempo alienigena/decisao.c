#include <stdio.h>

int main ()
{
    int d, m, h, min, s, tempo, dias = 0;
    int br, ma, sa, ta, blips;

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
    dias += d;

    tempo = dias*86400 + h*3600 + min*60 + s;
    blips = tempo / 3;

    br = blips / 144000;
    blips = blips - (br*144000);
    ma = blips / 18000;
    blips = blips - (ma*18000);
    sa = blips / 600;
    blips = blips - (sa*600);
    ta = blips / 40;
    blips = blips - (ta*40);

    printf("%i brat, %i mazel, %i salek, %i taks, %i blips", br, ma, sa, ta, blips);
}