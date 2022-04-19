// Implementieren Sie hier ein struct mit Namen "bruch".
typedef struct{
    int zaehler;
    int nenner;
}bruch;
// Verwenden Sie "typedef", um den Namen zu vergeben.

void kuerze(bruch* a);
void print(bruch a, char ausgabe[100]);
bruch product(bruch a, bruch b); // Hinweis: Ergebnis kürzen!
