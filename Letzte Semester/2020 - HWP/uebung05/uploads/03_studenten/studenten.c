#include "studenten.h"

//Maus Micky 12345 18 11 1928 ja Mathematik
void student_einlesen(student *s, FILE *in){
    char fach[20];
    fscanf(in, "%s %s %d %d %d %d %s %s", s->name, s->vorname, &s->matnr, &s->geburtstag.tag, &s->geburtstag.monat, &s->geburtstag.jahr, s->zulassung, fach);
    s->hauptfach = studienfach_einlesen(fach);
}

student* aeltester_student(student *studenten, int anzahl){
    int min_index = 0;
    for (int i = 1; i < anzahl; i++)
    {
        if(datum_vergleichen(studenten[i].geburtstag, studenten[min_index].geburtstag) < 0){
            min_index = i;
        }
    }
    return &studenten[min_index];
}
