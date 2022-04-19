#include <stdio.h>
#include <string.h>
typedef struct haustier{
	char name[7];
} haustier; 

void name_setzen(haustier *t, char *tier);
void only_letter(char *name);
int ivalid(char symbol);
void first_letter(char *name);
void name_ausgeben(char *name, haustier *tier);
