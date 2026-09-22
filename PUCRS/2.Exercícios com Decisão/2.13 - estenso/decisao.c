#include <stdio.h>
#include <math.h>

int main ()
{
    int a, b, c, num; 
    printf ("entre o numero - ");
    scanf("%i", &num);

    c = num % 10;
    b = num % 100 / 10;
    a = num % 1000 / 100;

    if ( a == 1) printf("cento e ");
    if ( a == 2) printf("duzentos e ");
    if ( a == 3) printf("trezentos e ");
    if ( a == 4) printf("quatrocentos e ");
    if ( a == 5) printf("quinhentos e ");
    if ( a == 6) printf("seicentos e ");
    if ( a == 7) printf("setecentos e ");
    if ( a == 8) printf("oitocentos e ");
    if ( a == 9) printf("novecentos e ");
    
    if (b == 1)
    {
        if (c == 1) printf("onze\n");
        if (c == 2) printf("doze");
        if (c == 3) printf("treze\n");
        if (c == 4) printf("catorze\n");
        if (c == 5) printf("quinze\n");
        if (c == 6) printf("desesseis\n");
        if (c == 7) printf("dezessete\n");
        if (c == 8) printf("dezoito\n");
        if (c == 9) printf("dezenove\n");
        if (c == 0) printf("dez\n");
    }
    else {
        if ( b == 2) printf("vinte e ");
        if ( b == 3) printf("trinta e ");
        if ( b == 4) printf("quarenta e ");
        if ( b == 5) printf("cinquenta e ");
        if ( b == 6) printf("sessenta e ");
        if ( b == 7) printf("setenta e ");
        if ( b == 8) printf("oitenta e ");
        if ( b == 9) printf("noventa e ");
        
        if (c == 1) printf("um\n");
        if (c == 2) printf("dois\n");
        if (c == 3) printf("tres\n");
        if (c == 4) printf("quatro\n");
        if (c == 5) printf("cinco\n");
        if (c == 6) printf("seis\n");
        if (c == 7) printf("sete\n");
        if (c == 8) printf("oito\n");
        if (c == 9) printf("nove\n");
    }
}