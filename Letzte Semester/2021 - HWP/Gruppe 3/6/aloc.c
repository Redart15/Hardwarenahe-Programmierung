#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef
struct LLong{
	char *name;
	struct men *next;
} men;
char *reserv(char *name);

int main(){
	char *name = "Langer Name";
	char *naame = "Längerer Name";
	char *naaame = "Längste Name";
	char *pnt0 = reserv(name);
	char *pnt1 = reserv(naame);
	char *pnt2 = reserv(naaame);
	printf("Lang: %s\tLänger: %s\tLong long meeen: %s\n",pnt0,pnt1,pnt2);
	free(pnt0);
	free(pnt1);
	free(pnt2);
}


char *reserv(char *name){
	unsigned int laenge = strlen(name) + 1;
	char *pnt = malloc(laenge);
	strncpy(pnt,name,laenge);
	return pnt;	
}
