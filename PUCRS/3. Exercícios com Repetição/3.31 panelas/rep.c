#include <stdio.h>

int main()
{
    int c1 = 50, c2 = 50, c3 = 50, c4 = 50;
    int w, x, y, z, total, menor = 100000;
    int p = 500, g = 200;
    
    for (w = 0; w <=50; w++){
        for (x = 0; x <=50; x++){
            for (y = 0; y <=50; y++){
                for (z = 0; z <=50; z++){
                    if (w*(6) + x*(2) + y*(4) == 500 && x*(2) + y + z*(3) == 200) total = w + x + y + z;
                    if (total < menor) menor = total;
                }
            }
        }
    }

    printf("menor numero de chapas neceesaria = %i\n", total);
    
    
}