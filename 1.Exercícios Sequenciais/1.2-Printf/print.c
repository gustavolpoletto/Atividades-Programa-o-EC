#include <stdio.h>

void main() {
    int a = 105;
    float x = 101.31;

    printf("Com d: %d\n", a );  //normal
    printf("Com 7d: %5d\n", a );  // completa x espaços antes, contando os espaços já usados pelo número
    printf("Com 07d: %07d\n", a );  // coloca x espaçoes e enche com zeros(nesse caso)
    printf("Com -7d: %-7d\n", a );  //coloca x espaços depois
    printf("Com f: %f\n", a );  // muda para float e da erro - 0.0000

    printf("\n\n");

    printf("Com 7f: %7f\n", x );  // coloca espaçamento, casas minimas
    printf("Com .3f: %.3f\n", x );  //x casas após a virgula
    printf("Com 7.4f: %7.4f\n", x );  // espaçamento + limitação de casas decimais
    printf("Com c : %c\n", a );  //muda para ascii
    printf("Com c : %c\n", x );  // erro
}