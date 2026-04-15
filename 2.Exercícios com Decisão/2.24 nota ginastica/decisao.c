#include <stdio.h>

int main ()
{
    float a, b, c, d, e, f;

    printf("Coloque as notas em ordem - ");
    scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f);

    float men = a, mai = b, flag = 0;

    if( b <= men) men = b;
    if( c <= men) men = c;
    if( d <= men) men = d;
    if( e <= men) men = e;
    if( f <= men) men = f;

    if( a > men) mai = a;
    if( a ==men) {flag = 1; mai = b;}
    if( b <= mai ) {
        if (b == men){
            if (flag == 0) flag++;
            else mai = b;
        }
        else mai = b; }
    if( c <= mai ) {
        if (c == men){
            if (flag == 0) flag++;
            else mai = c;
        }
        else mai = c; }
    if( d <= mai ) {
        if (d == men){
            if (flag == 0) flag++;
            else mai = d;
        }
        else mai = d; }
    if( d <= mai ) {
        if (d == men){
            if (flag == 0) flag++;
            else mai = d;
        }
        else mai = d; }
    if( e <= mai ) {
        if (e == men){
            if (flag == 0) flag++;
            else mai = e;
        }
        else mai = e; }
    if( f <= mai ) {
        if (f == men){
            if (flag == 0) flag++;
            else mai = f;
        }
        else mai = f; }

    

    printf("nota final -> %.2f\n", (a+b+c+d+e+f-men-mai)/4);
}