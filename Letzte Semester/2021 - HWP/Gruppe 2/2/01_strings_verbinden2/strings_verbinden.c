/*
 * Implementieren Sie hier die Funktion "strings_verbinden".
 * Es soll zwei String angenohmen werden, diese sollen dann in
 * Umgekehrter Reihenfolge zusammen gesetz werden.
 */
#include <stdio.h>
#include <string.h>

void strings_verbinden(char zusammen[], char string0[], char string1[]);
void string_umkehren(char umgekehrt[]);

void strings_verbinden(char zusammen[], char string0[], char string1[]){
	string_umkehren(string0);
	string_umkehren(string1);
	
	int length = strlen(string0) + strlen(string1);
	memset(zusammen,0,length);
	/* 
	 * ermittlet die Länge des Endstrings und ini das Array mit lauter
	 * Nullen, ursprünglich hat valdring nonstop gemekert weil das array,
	 * nicht initialisiert war.
	 */
	 
	strcpy(zusammen,string0);
	strcat(zusammen,string1);	
	/* 
	 * copiert den ersten string ins array "zusammen", und hängt den
	 *  zweiten String hintendran
	 */
}
void string_umkehren(char umgekehrt[]){
	int length = strlen(umgekehrt);
	if(length==0){return;}
	/* 
	 * checkt die länge des strings, welches genutzt wird um array zu
	 * initialisieren. Ist der String leer so wird dies an der länge 
	 * erkannt und die funktion augenblicklich verlassen.
	 */
	char kehr_mich[length];
	memmove(kehr_mich,umgekehrt,length);
	/* 
	 * ermittlet die Länge des Endstrings und ini das Array mit lauter
	 * Nullen, ursprünglich hat valdring nonstop gemekert weil das array,
	 * nicht initialisiert war.
	 */

	
	for(int cnt=0;cnt!=length; cnt++){
		umgekehrt[cnt] = kehr_mich[length-1-cnt];
		/*
		 *  kopiert aus dem kehr_mich array ,von hinten nach vorne,
		 * die Elemente ins umgekehrt, von vorne nach hinten, und kehrt 
		 * somit das 
		 */
	}
}
