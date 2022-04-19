/* Schreiben Sie ein Programm, in dem zwei double Zahlen von der 
 * Tastatur eingelesen und in lokalen Variablen gespeichert werden. 
 * Die Werte der Variablen sollen anschließend in einer Funktion 
 * namens swap miteinander vertauscht werden. Geben Sie die beiden 
 * Variablen vor und nach dem Aufruf von swap auf dem Bildschirm aus.*/
#include <stdio.h>

/*ini funtctions*/
double eingabe();
void swap(double* first, double* second);
void ausgabe(double first, double second);

/* function space*/
int main(){
	//aufgefordert zwei Zahlen einzugeben
	printf("Die  erste Zahl:");
	double first = eingabe();
	printf("Die zweite Zahl:");
	double second = eingabe();
	
	//ausgabe der Ursprungsreihenfolge
	printf("Die Reihenfolge ist: %3lf, %3lf\n", first, second);
	
	//tauscht die zahlen, und gibt diese aus.
	swap(&first,&second);
	ausgabe(first, second);
	return 0;
}
double eingabe(){
	double eingabe;
	scanf("%lf",&eingabe);
	return eingabe;
}
void swap(double* first, double* second){
	/* ini lokale variable als zwischenspeicher, speichert var.first da 
	 * tauscht die variablens Werte*/
	double zwischen = *first;
	*first = *second;
	*second = zwischen;
}
void ausgabe(double first, double second){
	//gibt die neue Reihenfolge aus.
	printf("Die neue Reihenfolge ist: %3lf, %3lf\n",first, second);
}
