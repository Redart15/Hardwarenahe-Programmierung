/*
 * experiment with pointers
 */


#include <stdio.h>
#include <getopt.h>

int eingabe();
void addone(int* cnt);
void ausgabe(int* cnt, int* ocnt);

int main(){
	printf("Eingabe: ");
	int cnt = eingabe();
	int ocnt = cnt;
	printf("cnt & ocnt: %i\n", cnt);
	addone(&cnt); // & wo es im Speicher steht
	ausgabe(&cnt, &ocnt);
	return 0;
}
int eingabe(){
	int value;
	scanf("%i", &value);
	return value;
}
void addone(int* cnt){
	*cnt += 1; //* was an der stelle im Speicher steht
}
void ausgabe(int* cnt, int* ocnt){
	printf("cnt: %i, ocnt: %i\n", *cnt, *ocnt);
	if(*cnt>*ocnt){printf("cnt hat sich verändert\n");}
}	
