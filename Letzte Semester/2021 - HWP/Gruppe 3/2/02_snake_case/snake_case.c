/*
 * Implementieren Sie hier die geforderte Funktion.
 */

#include <stdio.h>
#include <string.h>

void zu_snake_case(char *string);
void add_underscore(char* string);
void size_down(char* string);

void zu_snake_case(char *string){
	printf("Das Original lautet:\t %s\n", string);					// für tests
	add_underscore(string);									
	printf("Mit Understrich lautet:\t %s\n", string);				// für tests
	size_down(string);
	printf("Mit Schrumpfung lautet:\t %s\n\n", string);				// für tests
}

void add_underscore(char* string){
	for(int cnt = 0;string[cnt]!='\0';cnt++){							
		if((string[cnt]>64)&&(string[cnt]<91)){					// findet Großbuchstaben
			memmove(string+cnt+1,string+cnt,strlen(string)-cnt);		// schaft Platz für ein Unterstrich
			string[cnt]='_';						// setzt Unterstrich vom Großbuchstaben
			cnt++; 								// überspring den Buchstaben
		}
	}
}
void size_down(char* string){
	for(int cnt = 0; string[cnt]!='\0';cnt++){							
		if(string[cnt]=='_'){							// findet die Unterstriche
			string[cnt+1] += 32;						// ändert den Nachgehenden Großbuchstaben zu einem kleinen um
		}
	}
}
