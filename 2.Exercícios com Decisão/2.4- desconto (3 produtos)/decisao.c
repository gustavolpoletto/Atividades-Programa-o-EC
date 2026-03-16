#include <stdio.h>

int main ()
{
    int a, b, c;
    int men, mai;

    float total;

    printf("Coloque os valores dos produtos - ");
    scanf("%d %d %d", &a, &b, &c);

    printf ("-- %d, %d, %d\n", a, b, c);

    if (a < b){
        men = a; 
        mai = b;
    }
    else{
        men = b; 
        mai = a;
    } 
    
    printf ("men - %d, mai - %d\n", men, mai);

    if( c < men)
        total = c*0.5 + men*0.75 + mai;
    
    else if( c > mai)
        total = men*0.5 + mai*0.75 + c;
    
    else
        total = men*0.5 + c*0.75 + mai;

    printf ("total a ser pago - R$%.2f", total);
}