/* 
 * pointer and arrays
 * function copy pointer, they do not change them.
 */


#include <stdio.h>
int eingabe();
int* tuwas(long len, int point[]);
void ausgabe(long cnt, int *zeig);

int main(){
	int zwis[3] ={0,1,2};
	long len = sizeof(zwis)/4;		
	//größe des Arrays, int: 4Bytes long 
	int *zeig = tuwas(len,zwis);
	ausgabe(len,zeig);
	return 0;
}
int* tuwas(long len, int point[]){
	//printf("Wir kommen hier an. %ld\n",cnt);	
	//Prüfe ob größe auch stimmt
	for(int cnt=0; cnt<len; cnt++){
		*point += 1;
		printf("Wert: %i - Adresse: %p\n",*point,point);
		point++;
		}
	return point;
}
void ausgabe(long len, int* zeig){
	zeig -= 3;
	for(int cnt=0; cnt<len; cnt++){
	printf("Der %i, Wert ist: %i,"
		   " an der Adresse: %p\n",cnt,*zeig,zeig);
	zeig++;
	}
}
