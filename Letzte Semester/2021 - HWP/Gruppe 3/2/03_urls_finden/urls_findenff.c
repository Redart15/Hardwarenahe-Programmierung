#include "urls_finden.h"

/* Implementieren Sie hier die geforderte Funktion. */


int urls_finden(char urls[10][150], char *text);		
//~ void conv(char* workspace);
int invalid(char zeichen);
char* ordnen(char* pnt1,char* pnt2,char* pnt3,char* last);
char* kleiner(char* pnt1,char* pnt2);



int urls_finden(char urls[10][150], char *text){
	int pos_url = 0,cnt=0;
	int txt_len = strlen(text);	
	char workspace[1000];
	char *https/*=workspace*/,*http/*=workspace*/,*www/*=workspace*/; 	// ini die zeiger mit gültiger adresse(safety net)
	memset(workspace,0,1000);								// ini workspace, garantiert das alle string nullterminiert sind
	memset(urls,0,1500);									// selbe wie bei workspace
	memmove(workspace,text,txt_len); 						// text ist im const., brauche ihn aber aufm stack 
	//~ workspace[txt_len]	= '|';								// schaffe zusätzlichen Platz, als referents für einen Zeiger, zeichen=invalid
	//~ workspace[txt_len+1]	= '\0';	
	
	char* badr = workspace+sizeof(workspace); 						// größt mögliche legitime Zeiger
	//~ conv(workspace); 										// danach muss man nur noch nach einem Zeichen prüfen
	for(pos_url=0;pos_url!=10;pos_url++){					
		https 	= strstr(workspace,"https://");				
		http 	= strstr(workspace,"http://");
		www  	= strstr(workspace,"www.");
		printf("0\thttps: %14p\thttp: %14p\twww: %14p\n",https,http,www);
		if((https==NULL)&&(http==NULL)&&(www==NULL)){		// sind alle Zieger NULL wird die Funktion beendet
		printf("1\thttps: %14p\thttp: %14p\twww: %14p\n",https,http,www);
			break;
		}
		https = ordnen(https,http,www,badr);				// kleinste Zeiger wird ermittelt, zum Vergleichen müssen alle Zeiger legal sein
	
		//~ for(cnt = 0; ((https[cnt] != ' ')&&(https[cnt] != '\0'));cnt++){
		for(cnt = 0; invalid(https[cnt])==0;cnt++){
			urls[pos_url][cnt] = https[cnt];				
			https[cnt] = ' ';								// eliminiert die bearbeitete URL
		}
	}
	return pos_url;
}
//~ void conv(char* workspace){
	//~ for(int pos_txt = 0; workspace[pos_txt]!='\0';pos_txt++){
		//~ if(invalid(workspace[pos_txt])){					// nicht erlaubte Zeichen werden durch 32 ersetzt
			//~ workspace[pos_txt]=' ';
		//~ }
	//~ }
//~ }
int invalid(char zeichen){									
	if((zeichen>34)&&(zeichen<60)){							// prüf ob das Zeichen erlaubt ist
		return 0;
		}
	if((zeichen>62)&&(zeichen<92)){
		return 0;
		}
	if((zeichen>96)&&(zeichen<123)){
		return 0;
		}
	char *extras = "!=]~_";
	for(int cnt = 0;extras[cnt]!='\0';cnt++){
		if(extras[cnt]==zeichen){
			return 0;
		}
	}
	return 1;												// gibt wahr aus wenn nicht sonst wird falsch ausgeben
}
char* ordnen(char* pnt1,char* pnt2,char* pnt3,char* last){
	char* erst = NULL;																			
	if(pnt1==NULL){											// wenn einer der Zeiger NULL ist wird er durch die letzte Adresse in workspace ersetzt
		pnt1=last;
		}
	if(pnt2==NULL){
		pnt2=last;
		}
	if(pnt3==NULL){
		pnt3=last;
		}	
	erst = kleiner(pnt1,pnt2);								// zwei Vergleich decken alle 6 möglichkeiten ab.
	erst = kleiner(erst,pnt3);
	return erst;											// resultat ist die erste URL, im Text.
}
char* kleiner(char* pnt1,char* pnt2){
	if(pnt1 < pnt2){										// gibt den kleiner Zeiger wieder
		return pnt1;
	}else{
		return pnt2;
	}
}
