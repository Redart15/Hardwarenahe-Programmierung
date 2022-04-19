/*
 * Binary converter, all input and output seperate functions
 */


#include <stdio.h>
int input();
int* dectobin(int number, int* len, int* array);
void output(int number, int len, int* pointer );

int main(){
	int number	= input();
	int max = 0x7FFFFFFF;
	//get a number
	
	if(number==0){printf("%i in Base_2: 0\n", number);return 0;}
		else if((number<0) || (number>max)){
			printf("Der Wert liegt außerhalb"
				   "der gültigen Bereiches!");
			return 0;
		}
	
	int len		= 16;
	//set length
	
	int array[(len-1)];
	//ini an array the size of 16.
	
	int *pointer = dectobin(number, &len, &array);
	/* dectobin gives back a pointer of an array, 
	 * modifies len to be the lenght of the array*/
	 
	output(number,len, pointer);
	/* takes number, for output, takes len as length of array
	* lastly uses pointer to adressen the array back*/
	return 0;
}
int input(){
/* input, output a promt, take in an int and give it back to main */
	int value;
	printf("Decimal to Binary\n");
	printf("Gebe sie eine Zahl ein: ");
	scanf("%i",&value);
	return value;
}
int* dectobin(int number, int* len, int* pointer){
	//keine Ahnung wieso hier der pointer eckige Klammern braucht...
	
	int cnt = *len-1;
	// saves the value
	
	for(cnt = 0; ((cnt<*len)&&(number!=0)); cnt++){
		*pointer = number & 1;
		number = number >> 1;
		//algorithmus to calc the binary number
		
		pointer++;
	}										
	*len = cnt;
	//set the array length and safe it up.
	
	return pointer;
	//gives back the pointer to main, to refrenz the array
}
void output(int number, int len, int* pointer ){
	pointer--;
	/* pointer get for what ever reason incremented
	 * by one more than needed*/
	 
	len -= 1;
	/* arrays start at zero, but length is not an index but the size.
	 * convert to index*/
	 
	printf("%i in Base_2: ",number); 
	for(; len>-1; len--){
		printf("%i",*pointer);
		pointer--;
		//print out the array in reverse order
	}
	printf("\n");
}

