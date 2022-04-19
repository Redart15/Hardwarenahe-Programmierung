#include "strings_ersetzen.h"

/* Implementieren Sie hier die geforderte Funktion. 
 * 
 *  "Dies ist ein Text und hier werden die Sternchen durch,"
	"Stings ersetzt, wolmöglich wird das eine interessante Angelegenheit,"
	"da es so aussieht als ob dies nicht die richtige Datei sei um rein"
	"zuschreiben, vlt mach ich einen Fehler und die Datei muss wo anders"
	"geschrieben werden...";
 * 
 * 
 * */
 
int strings_ersetzen(char ausgabe[], char *text, char strings[100][100]);
int len_array(char strings[100][100]);
void einsetzen(char* text,char strings[100][100]);
void smuggle(char* text,char strings[100][100]);

//~ int main(){
	//~ char strings[100][100]= 
	//~ {"Dies","und","werden","ersetzt","interessante","aussieht",
	 //~ "richtige","Fehler","die","muss","werden"};
	
	
	//~ char *text ="*** ist ein Text * hier *** die Sternchen durch "
	//~ "Stings ***, wolmöglich wird das eine ***** Angelegenheit,"
	//~ "da es so ** als ob dies nicht die **** Datei sei um rein"
	//~ "zuschreiben, vlt mach ich einen ** und ** Datei *** wo anders"
	//~ "geschrieben ****...";

	//~ char strings[100][100];
	//~ char *text = "Hello, World!"
	
	//~ char ausgabe[1000];
	
	//~ int anzahl = strings_ersetzen(ausgabe,text,strings);
	//~ /* gibt die Anzahl ersetzer Sternchenstrings*/
	//~ printf("%i\n",anzahl);
	//~ printf("%s\n",ausgabe);	   
	//~ int cnt=0;
	//~ printf("Gegriegt was:\t");
	//~ for(;strings[cnt][0]!=0;cnt++){
		//~ printf("%s,",strings[cnt]); 
	//~ }
	//~ printf("\nZuerwarten was:\t"
		   //~ "***,*,***,***,*****,**,****,**,**,***,****");
	//~ printf("\nDer Count ist 11 = %i.\n",cnt);
	//~ return 0;
//~ }

int strings_ersetzen(char ausgabe[], char *text, char strings[100][100]){
	memset(ausgabe,0,1000);	
	int pos_text = 0,pos_array = 0,pos_ltz = 0,cpy_len = 0;
	int txt_len = strlen(text);
	
	for(;pos_text<txt_len;pos_text++){
		//~ printf("txt");
		if(text[pos_text]=='*'){
			printf("cpy_len:%i\n",cpy_len);
	
			strncat(ausgabe,&text[pos_ltz],cpy_len);
			pos_ltz += cpy_len;
			cpy_len = 0;
			
			for(;text[pos_text]=='*';pos_text++){
				//~ printf("star");
				pos_ltz++;}
			int str_len = strlen(strings[pos_array]);
			strncat(ausgabe,strings[pos_array],str_len);
			
			if(pos_array>len_array(strings)){return 1;}	
			pos_array++;
			//~ pos_text--;
		}
		cpy_len++;
	}
	if(pos_text==txt_len){strncat(ausgabe,&text[pos_ltz],cpy_len);}
	smuggle(text,strings);
	return pos_array;
}
int len_array(char strings[100][100]){
	int cnt = 0;
	for(;strings[cnt][0]!='\0';cnt++){
		//~ printf("cnt");
		}
	return cnt;
}
void smuggle(char* text,char strings[100][100]){
	int pos_text=0,pos_array=0,cnt=0;
	int s_text=strlen(text);
	for(;s_text>pos_text;pos_text++){
		if(text[pos_text]=='*'){
			for(;text[pos_text]=='*';cnt++){
				//~ printf("%2i,current array\t%6s,current string\n",pos_array,strings[pos_array]);
				strings[pos_array][cnt]=text[pos_text];
				strings[pos_array][cnt+1]=0;
				pos_text++;
			}
		pos_array++;
		if(pos_array>10){return;}
		cnt=0;
		}
		//~ strings[pos_array][cnt]=0;
		//~ printf("%2i,current array\t%6s,current string\n",pos_array,strings[pos_array]);
	}
}
