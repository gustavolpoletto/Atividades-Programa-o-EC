#include <stdio.h>

char ehNumero(char f[]){
    int i = 0, virgula = 0, neg = 0;
    while(f[i] != '\0' ){
        if (f[i] == ',' || f[i] == '.'){
            if (++virgula > 1) return 'n'; 
        }
        else if (f[i] == '-' && i != 0) return 'n';
        else if (f[i] < '0' || f[i] > '9') return 'n'; 
        i++;
    }
    return 's';
    
}
int main(){
    // char f[] = "Ola mundo!";
    // char f[] = "34";
    char f[] = "3.1415";
    // char f[] = "3.14.15!";
    printf("%c\n", ehNumero(f));

}