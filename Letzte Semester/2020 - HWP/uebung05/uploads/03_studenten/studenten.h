#include "../02_datum/datum.h"
#include <stdio.h>
#include <string.h>

/*
 * Implementieren Sie hier:
 * - ein enum mit Namen studienfach
 * - ein struct mit Namen student.
 */
typedef enum
{
    PHYSIK,
    MATHEMATIK,
    INFORMATIK
} studienfach;

typedef struct
{
    char name[100];
    char vorname[100];
    int matnr;
    datum geburtstag;
    char zulassung[5];
    studienfach hauptfach;
} student;

void student_einlesen(student *einstudent, FILE *eingabe);
void student_ausgeben(student *einstudent, FILE *ausgabe);
studienfach studienfach_einlesen(char *fach);
void studienfach_ausgeben(studienfach fach, FILE *ausgabe);
student *aeltester_student(student *studenten, int anzahl);
