#include <stdio.h>

int contagemVogais(char f[]){
    int c = 0;
    while(f[0] != '\0'){
        if (f[0] == 'a' ||f[0] == 'A' ||f[0] == 'e' ||f[0] == 'E' ||f[0] == 'i' ||f[0] == 'I' ||f[0] == 'o' ||f[0] == 'O' ||f[0] == 'u' ||f[0] == 'U') c++;
        f++;
    }
    return c;
    
}
int main(){
    char f[] = "Ola mundo!";
    printf("%d vogais\n", contagemVogais(f));

}