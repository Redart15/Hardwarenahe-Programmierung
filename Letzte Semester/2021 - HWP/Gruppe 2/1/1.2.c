/* (a) Schreiben Sie ein Programm, das 12 Messwerte 
 * (jeweils vom Typ double) von der Konsole in ein Array einliest und 
 * den Inhalt des Arrays anschließend ausgibt.
 * 
 * (b) Falls Sie in Ihrer Loesung eckige Klammern, also [], fuer die 
 * Lese- und Schreibzugriffe auf das Array verwendet haben, schreiben 
 * Sie Ihr Programm so um, dass es stattdessen Pointerzugriffe 
 * verwendet! Verwenden Sie eckige Klammern hier also nur noch zur 
 * Deklaration des Arrays.*/
 #include <stdio.h>

/*ini funtctions*/
void eingabe_a(int len, int cnt, double* point);
void ausgabe_a(int len, int cnt, double* point);

/* function space*/
int main(){
	/* len is the size of the array
	 * cnt, ini here so no need to do in function*/
	int len = 12;
	int cnt = 0;
	
	/* define the array to be lenght len. set pointer to first element 
	 * of the array
	 * pointer only gets copied into funktion and can be used without 
	 * additional arithemtics*/
	double array[len];
	double *point = array;
	/* controll, via Adress, no use anymore, so commented out.
	 * printf("Adresse von point: %p\n",point);*/
	
	/* function space */
	eingabe_a(len,cnt,point);
	ausgabe_a(len,cnt,point);
	return 0;
}
void eingabe_a(int len, int cnt, double* point){
	/* fills the array, with user input, with len amout of elements*/
	for(; cnt<len; cnt++){
		printf("%i. Zahl ist: ",cnt);
		scanf("%lf,\n", point);
		point++;
	}
	printf("\n");
}
void ausgabe_a(int len, int cnt, double* point){
	/* prints out the elements of the array*/
	for(; cnt<len; cnt++){
		printf("%i. Zahl ist: %lf\n",cnt, *point);
		point++;
	}
}
