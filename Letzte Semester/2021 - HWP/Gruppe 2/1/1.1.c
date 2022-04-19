/*
 * (a) Erstellen Sie eine Funktion even(int a), die testet, ob a eine 
 * gerade Zahl ist. Falls a gerade ist, soll 1 als Rueckgabewert 
 * werden, andernfalls 0. 
 * 
 * (b) Schreiben Sie ein Programm, das mit Ihrer 
 * Funktion aus (a) eine Zahl x testet und dem Benutzer am Bildschirm 
 * eine Meldung ausgibt, ob die Zahl gerade oder ungerade ist. Dabei 
 * soll der Benutzer nach Programmstart aufgefordert werden, die Zahl x 
 * einzugeben. Beispiel:
 * Geben Sie eine Zahl ein: 15
-------------------------------------
 * Die Zahl ist nicht gerade!
 */


#include <stdio.h>
int eingabe();
int even(int a);
void ausgabea(int a);
void ausgabeb(int a);

int main(){
	printf("Geben sie eine Zahl ein: ");
	int a = eingabe();
	ausgabea(a);
	printf("Geben sie eine Zahl ein: %i\n", a);
	ausgabeb(a);
	return 0;
}
int eingabe(){
	int value;
	scanf("%i", &value);
	return value;
}
int even(int a){
	a = a & 1;
	return a;
}
void ausgabea(int a){
	printf("%i\n",even(a));
}
void ausgabeb(int a){
	printf("-------------------------------------\n");
	if(even(a)>1){printf("Die Zahl ist nicht gerade");}
	else         {printf("Die Zahl ist gerade");}
	printf("\n");
}

