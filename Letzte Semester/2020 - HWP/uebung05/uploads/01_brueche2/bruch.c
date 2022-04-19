#include "bruch.h"
#include <stdio.h>

int gcd(int a, int b)
{ //wikipedia
    if (b == 0)
    {
        return a;
    }
    if (a == 0)
    {
        return b;
    }
    if (a > b)
    {
        return gcd(a - b, b);
    }
    return gcd(a, b - a);
}

/* Implementieren Sie hier die benötigten Funktionen. */
void kuerze(bruch *a)
{
    int common_divisor = gcd(a->nenner, a->zaehler);
    a->nenner = a->nenner / common_divisor;
    a->zaehler = a->zaehler / common_divisor;
}
void print(bruch a, char ausgabe[100]){
    snprintf(ausgabe, 100*sizeof(char), "%f", (double)a.zaehler/(double)a.nenner);
}
bruch product(bruch a, bruch b){
    bruch c = {.nenner=a.nenner*b.nenner, .zaehler=a.zaehler*b.zaehler};
    kuerze(&c);
    return c;
} // Hinweis: Ergebnis kürzen!