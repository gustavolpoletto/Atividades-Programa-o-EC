#include <stdio.h>

void contagem(char f[], int*v, int*c, int*s){
    while(f[0] != '\0'){
        if (f[0] == 'a' ||f[0] == 'A' ||f[0] == 'e' ||f[0] == 'E' ||f[0] == 'i' ||f[0] == 'I' ||f[0] == 'o' ||f[0] == 'O' ||f[0] == 'u' ||f[0] == 'U') (*v)++;
        else if((f[0] >= 'a' && f[0] <= 'z') || (f[0] >= 'A' && f[0] <= 'Z')) (*c)++;
        else (*s)++;
        f++;
    }
}
int main(){
    char f[] = "Ola mundo!";
    int v = 0, c = 0, s = 0;
    contagem(f, &v, &c, &s);
    printf("v- %d, c- %d s-%d\n", v, c, s);

}