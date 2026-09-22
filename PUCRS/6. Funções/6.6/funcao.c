#include <stdio.h>

float atof(char f[]){
    int i = 0, virgula = 0, neg = 1, flagDec = 0, inteiro = 0 , dec = 0, div = 1;
    while(f[i] != '\0' ){
        if (f[i] == '-') neg = -1;
        else if (f[i] == ',' || f[i] == '.') flagDec = 1;
        else if (flagDec == 0){
            inteiro *= 10;
            inteiro += f[i]-'0';
        }
        else{
            dec *= 10;
            dec += f[i]-'0';
            div *= 10;
        }
        i++;
    }
    return neg*(inteiro + (dec * 1.0 / div));
    
}
int main(){
    char f[] = "34";
    // char f[] = "3.1415";
    // char f[] = "3.0";
    printf("%f\n", atof(f));

}