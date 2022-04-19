#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Implementieren Sie hier ein struct mit Namen student. */
struct student
{
    int matnr;
    char name[100];
    struct student *next;
};
typedef struct student student;

/* Implementieren Sie die folgenden Funktionen. */
student *student_einfuegen(student *studenten, char *name, int matnr);
void studenten_ausgeben(student *studenten, FILE *ausgabe);
student *studenten_einlesen(FILE *eingabe);
void studenten_freigeben(student *studenten);
student *new_student(int matnr, char* name, student *next);

student *new_student(int matnr, char* name, student *next){
    student *new_student = malloc(sizeof(student));
    new_student->matnr = matnr;
    strcpy(new_student->name, name);
    new_student->next = next;
    return new_student;
}

student *student_einfuegen(student *studenten, char *name, int matnr)
{
    if(studenten == NULL){
        return new_student(matnr, name, NULL);
    }
    student *student_ref = studenten;

    if(student_ref->matnr > matnr){
        return new_student(matnr, name, student_ref);
    }

    while(student_ref->next != NULL){
        if(student_ref->next->matnr > matnr){
            student *n_student = new_student(matnr, name, student_ref->next);
            student_ref->next = n_student;
            return studenten;
        }
        student_ref = student_ref->next;
    }
    student_ref->next = new_student(matnr, name, NULL);
    return studenten;
}

student *studenten_einlesen(FILE *eingabe)
{
    int matnr;
    char name[100];
    student *student = NULL;
    while (fscanf(eingabe, "%d %s", &matnr, name) != EOF)
    {
        student = student_einfuegen(student, name, matnr);
    }
    return student;
}

void studenten_ausgeben(student *studenten, FILE *ausgabe)
{
    student *student_ref = studenten;
    while (student_ref != NULL)
    {
        fprintf(ausgabe, "%d %s\n", student_ref->matnr, student_ref->name);
        student_ref = student_ref->next;
    }
}

void studenten_freigeben(student *studenten)
{
    student *student_ref = studenten;
    while (student_ref != NULL)
    {
        student *next_student = student_ref->next;
        free(student_ref);
        student_ref = next_student;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }

    // Studenten einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    student *studenten = studenten_einlesen(eingabe);
    fclose(eingabe);

    // Studenten ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    studenten_ausgeben(studenten, ausgabe);
    fclose(ausgabe);

    studenten_freigeben(studenten);

    return 0;
}
