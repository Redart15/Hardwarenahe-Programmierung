#include "urls_finden.h"

/* Implementieren Sie hier die geforderte Funktion. */


int urls_finden(char urls[10][150], char *text);		
int invalid(char zeichen);
char* ordnen(char* pnt1,char* pnt2,char* pnt3,char* last);
char* kleiner(char* pnt1,char* pnt2);



int urls_finden(char urls[10][150], char *text){
	int pos_url = 0;
	char *https,*http,*www,*link;
	char* bard = text+strlen(text);
	 																
	memset(urls,0,1500);																									
	for(pos_url=0;pos_url!=10;pos_url++){
		link = &(urls[pos_url][0]);					
		https 	= strstr(text,"https://");				
		http 	= strstr(text,"http://");
		www  	= strstr(text,"www.");
		printf("https: %14p\thttp: %14p\twww: %14p\n",https,http,www);
		if((https==NULL)&&(http==NULL)&&(www==NULL)){		
			break;
		}
		https = ordnen(https,http,www,bard);
		while((*https != 0) && invalid(*https)){
			*(link++) = *(https++);					
		}
		text = https;
	}
	printf("\n");
	return pos_url;
}
int invalid(char zeichen){									
	if((zeichen>34)&&(zeichen<60)){						
		return 1;
		}
	if((zeichen>62)&&(zeichen<92)){
		return 1;
		}
	if((zeichen>96)&&(zeichen<123)){
		return 1;
		}
	char *extras = "!=]_~";
	for(int cnt = 0;extras[cnt]!='\0';cnt++){
		if(extras[cnt]==zeichen){
			return 1;
		}
	}
	return 0;												
}
char* ordnen(char* pnt1,char* pnt2,char* pnt3,char* last){
	char* erst = NULL;																			
	if(pnt1==NULL){											
		pnt1=last;
		}
	if(pnt2==NULL){
		pnt2=last;
		}
	if(pnt3==NULL){
		pnt3=last;
		}	
	erst = kleiner(pnt1,pnt2);								
	erst = kleiner(erst,pnt3);
	return erst;											
}
char* kleiner(char* pnt1,char* pnt2){
	if(pnt1 < pnt2){										
		return pnt1;
	}else{
		return pnt2;
	}
}
