/*
 * Implementieren Sie hier die geforderte Funktion.
 * Diese Soll ein String einlesen, alle klein Buchstaben rechts vom 
 * Unterstrich vergrößern. Anschließend werden alle Unterstriche entfernt
 */
#include <stdio.h> 
#include <string.h>
/*
 * tape in terminal, to execute this code
 * make camel_case
 * make run
 * */

void zu_camel_case(char *string);
void size_up_underscore(char* string);
void remove_underscore(char* string);

void zu_camel_case(char* string){
	size_up_underscore(string);
	/* 
	 * size_up_underscore:
	 * 		caps all letters in front of underscore
	 */
	 
	remove_underscore(string);
	/* 
	 * remove_underscore:
	 * 		delets all underscores
	 */
}

void size_up_underscore(char* string){
	for(int cnt=0;strlen(string)>cnt;cnt++){							
		if((string[cnt]=='_')&&(string[cnt+1]>96)&&(string[cnt+1]<123)){					
			string[cnt+1] -= 32;
		}
		/* 
		 * checks for underscore at the current pos. and checks if the 
		 * following pos is a letter, if so decrements the value by 32
		 * in other word turns decaps the letter.
		 */
	}
}
void remove_underscore(char* string){
	for(int cnt=0;strlen(string)>cnt;cnt++){
		if((string[cnt]=='_')){											
			memmove(string+cnt,string+cnt+1,strlen(string)-cnt);
			cnt--;
		}
		/* 
		 * checks for underscore at current pos. , if so it takes the
		 * remaining string, beginnning at next pos. and copies it to
		 * the current one, thus overwritting the char at that location
		 * it than steps back by one step and repeats the process.
		 * */
	}
}

