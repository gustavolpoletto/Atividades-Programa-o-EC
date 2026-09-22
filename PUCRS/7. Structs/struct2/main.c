#include <stdio.h>

struct data{
    int dia, mes, ano;
};

void printData (struct data a){
    printf("%d/%d/%d\n", a.dia, a.mes, a.ano);
}

void dataMaisAntiga (struct data a, struct data b){
    if (a.ano < b.ano) {printData(a); return;}
    if (a.ano > b.ano) {printData(b); return;}
    
    if (a.mes < b.mes) {printData(a); return;}
    if (a.mes > b.mes) {printData(b); return;}
    
    if (a.dia < b.dia) {printData(a); return;}
    if (a.dia > b.dia) {printData(b); return;}
    
    printf("Mesmo Dia - ");
    printData(a);
}

int main(){
    struct data a = {2, 3, 2000};
    struct data b= {1, 1, 1991};
    struct data c = {28, 7, 2007};
    struct data d = {22, 7, 2007};
    struct data e = {22, 7, 2007};
    
    dataMaisAntiga(a, b);
    dataMaisAntiga(a, c);
    dataMaisAntiga(c, d);
    dataMaisAntiga(e, d);
}




