#include "studenten.h"

int main(int argc, char **argv){
    FILE *eingabe = stdin;
    FILE *ausgabe = stdout;

    student studenten[10];

    /* Studenten einlesen. */
    for (int i = 0; i < 10; i++){
        student *einstudent = &studenten[i];

        student_einlesen(einstudent, eingabe);
    }

    /* Studenten ausgeben. */
    for (int i = 0; i < 10; i++){
        fprintf(ausgabe, "Student %i:\n", i + 1);

        student *einstudent = &studenten[i];

        student_ausgeben(einstudent, ausgabe);
    }

    /* Den ältesten Studenten ausgeben. */
    fprintf(ausgabe, "Der älteste Student ist:\n");
    student *aeltester = aeltester_student(studenten, 10);
    student_ausgeben(aeltester, ausgabe);

    return 0;
}

studienfach studienfach_einlesen(char* fach){
    if (strcmp(fach, "Physik") == 0) return PHYSIK;
    if (strcmp(fach, "Informatik") == 0) return INFORMATIK;
    return MATHEMATIK;
}

void studienfach_ausgeben(studienfach fach, FILE *ausgabe){
    switch (fach){
        case PHYSIK:
            fprintf(ausgabe, "Physik");
            break;
        case MATHEMATIK:
            fprintf(ausgabe, "Mathematik");
            break;
        default:
            fprintf(ausgabe, "Informatik");
    }
}

void student_ausgeben(student *einstudent, FILE *ausgabe){
    fprintf(
        ausgabe,
        "---------------------------------------------------\n"
        "Name      : %s\n"
        "Vorname   : %s\n"
        "Matrikel  : %i\n"
        "Geburtstag: ",
        einstudent->name,
        einstudent->vorname,
        einstudent->matnr
    );
    datum_ausgeben(einstudent->geburtstag, ausgabe);
    fprintf(ausgabe, "\n");
    fprintf(
        ausgabe,
        "Zulassung : %s\n"
        "Hauptfach : ",
        einstudent->zulassung
    );
    studienfach_ausgeben(einstudent->hauptfach, ausgabe);
    fprintf(ausgabe, "\n");
    fprintf(ausgabe, "---------------------------------------------------\n");
}
