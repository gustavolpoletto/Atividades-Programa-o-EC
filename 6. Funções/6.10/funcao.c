#include <stdio.h>

void virapalavra(char frase[]){
    int s = 0, e = 0;
    while (frase[e] != '\0'){

        while(frase[e] != ' ' && frase[e] != '\0') {e++;}

        int r = e - 1;
        while(s < r){
            char temp = frase[s];
            frase[s] = frase[r];
            frase[r] = temp;

            s++; r--;
        }


        e++;
        s = e;
    }
}

int main(){
    char frase[] = "Papagaio Azul e Verde";
    printf("%s\n", frase);
    virapalavra(frase);
    printf("%s\n", frase);

}