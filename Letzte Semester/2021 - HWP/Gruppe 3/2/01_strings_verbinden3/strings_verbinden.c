/*
 * Implementieren Sie hier ihre Lösung.
 */
#include <stdio.h> 
#include <string.h> 
 

void strings_verbinden(char* zusammen,char* str1,char* str2,char* str3);
void anstecken(char* zusammen, char* string);

void strings_verbinden(char* zusammen,char* str1,char* str2,char* str3){
	zusammen[0] = 0;								// zusammen wird terminiert, wichtig für die Funktion
	anstecken(zusammen,str1);							// die Funktion hängt ein String an "zusammen" ran
	anstecken(zusammen,str2);
	anstecken(zusammen,str3);
	//~ zusammen[strlen(zusammen)]= 0;							//redundant, safety net, der String wird auf jedenfall terminiert.
}

void anstecken(char* zusammen, char* string){
	int str_len = strlen(string);										
	int sam_len = strlen(zusammen);							// wichtig: Zusammen muss bei ersten durchlauf länge Null haben
	int cnt = 0;
	for(;cnt<str_len+1; cnt++){
		zusammen[cnt+sam_len]=string[cnt];					// hängt der String an "zusammen" ran, inklusive des Nullterminators
	}
	//~ zusammen[cnt+sam_len] = 0;							// terminiert den string, counter wird am Ende der schleife immer inc. 
}
