#include <stdio.h>
#include <string.h>

int main(){
    unsigned int fach = 0;
    unsigned int semester = 0;
    unsigned int note;
    char anmerkung[120];

    printf("Welches Fach studieren Sie? (1: Informatik, 2: Mathematik, 3: Physik)\n");
    scanf("%i", &fach);
    while(getchar() != '\n');
    
    printf("In welchem Fachsemester studieren Sie? (1-12)\n");
    scanf("%i", &semester);
    while(getchar() != '\n');

    printf("Bitte benoten Sie Ihre Übung in Schulnoten. (1-6)\n");
    scanf("%i", &note);
    while(getchar() != '\n');

    printf("Haben Sie weitere Anmerkungen?\n");
    fgets(anmerkung, 120, stdin);

    //...
}


