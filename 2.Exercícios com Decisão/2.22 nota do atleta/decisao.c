#include <stdio.h>

int main ()
{
    float a, b, c, d, e, f, g, h;

    printf("Coloque as notas em ordem - ");
    scanf("%f %f %f %f %f %f %f %f", &a, &b, &c, &d, &e, &f, &g, &h);

    float men = a, mai = a;

    if( b < men) men = b;
    if( c < men) men = c;
    if( d < men) men = d;
    if( e < men) men = e;
    if( f < men) men = f;
    if( g < men) men = g;
    if( h < men) men = h;
    if( b > mai) mai = b;
    if( c > mai) mai = c;
    if( d > mai) mai = d;
    if( e > mai) mai = e;
    if( f > mai) mai = f;
    if( g > mai) mai = g;
    if( h > mai) mai = h;

    printf("nota final -> %.2f\n", (a+b+c+d+e+f+g+h-men-mai)/6);
}