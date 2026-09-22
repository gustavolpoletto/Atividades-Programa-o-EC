#include <stdio.h>

struct fracao{
    int num, den;
};

struct fracao mult(struct fracao a, struct fracao b ){
    struct fracao res;
    res.num = a.num * b.num;
    res.den = a.den * b.den;
    
    return res; 
}

struct fracao add(struct fracao a, struct fracao b ){
    struct fracao res;
    res.num = a.num * b.den + b.num * a.den;
    res.den = a.den * b.den;
    
    return res; 
}

struct fracao reduce( struct fracao a ){
    int num = a.num, den = a.den;
    int men = (num < den) ? num : den;
    
    for (int i = 2; i < men; i++){
        if (num % i == 0 && den % i == 0){
            num /= i; den /= i;
            i--;
        }
    }
    struct fracao res;
    res.num = num; res.den = den;
    
    return res; 
}

int main()
{
    
    struct fracao a = {2, 6} , b = {8, 4};
    struct fracao c = mult(a, b);
    struct fracao d = add(a, b);
    
    printf("%d/%d || %d/%d\n", c.num, c.den, d.num, d.den);
    c = reduce(c);
    d = reduce(d);
    printf("%d/%d || %d/%d\n", c.num, c.den, d.num, d.den);

    return 0;
}
