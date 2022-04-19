#include "urls_finden.h"

/* Implementieren Sie hier die geforderte Funktion. */

int urls_finden(char urls[10][150], char *text);
void tokkenize(char* workspace,char* text);
int invalid(char zeichen);
int cut_it(char workspace[],char tok_liste[100][150]/*,int* cnt_liste*/);
int header_test(char tok_liste[100][150],char urls[10][150],int* cnt_liste);

//~ int main(){
	//~ char urls[10][150];
	//~ char *text = "https://www.example.com   http://example.com   und   www.example.com   ";
	//~ char *text = "Hello, World";
	//~ char *text = "wwwachnedochnicht";
	//~ printf("Initial:\n%s\n\n",text);	
	//~ int cnt = urls_finden(urls,text);	
	//~ return cnt;																						
//~ }


int urls_finden(char urls[10][150], char *text){
	int cnt_liste = 0;
	char workspace[1000];
	char tok_liste[100][150];
	
	memset(urls,0,1500); 																		
	memset(workspace,0,1000);
	
	tokkenize(workspace,text);
	cnt_liste = cut_it(workspace,tok_liste);
	printf("Die Anzahl an Elementen in der Liste: %d\n\n",cnt_liste);
	cnt_liste = header_test(tok_liste,urls,&cnt_liste);
	printf("Die Anzahl an Urls ist: %d\n\n",cnt_liste);
	return cnt_liste;
}
void tokkenize(char* workspace,char* text){
	int txt_len = strlen(text);
	memmove(workspace,text,txt_len);
	for(int pos_txt = 0; workspace[pos_txt]!='\0';pos_txt++){
		if(invalid(workspace[pos_txt])){
			workspace[pos_txt]=' ';
		}
	}
	printf("After Tokkenize:\n%s\n\n",workspace);	
}
int invalid(char zeichen){
	if((zeichen>34)&&(zeichen<60)){return 0;}
	if((zeichen>62)&&(zeichen<92)){return 0;}
	if((zeichen>96)&&(zeichen<123)){return 0;}
	char *extras = "!=]~_";
	for(int cnt = 0;extras[cnt]!='\0';cnt++){
		if(extras[cnt]==zeichen){
			return 0;
		}
	}
	return 1;
}
int cut_it(char workspace[],char tok_liste[100][150]/*,int* cnt_liste*/){
	int pos_array = 0;
	int cnt_liste = 0;
	memset(tok_liste,0,15000);
	 printf("After Cut_it:\n");
	
	char* tok_speicher = strtok(workspace," ");		
	for (;tok_speicher != NULL;pos_array++) {
		strcat(tok_liste[pos_array],tok_speicher);
        tok_speicher = strtok(NULL, " ");
        printf("%s\n",tok_liste[pos_array]);
		cnt_liste++; 
    }
    printf("\n\n");
    return cnt_liste;
}
int header_test(char tok_liste[100][150],char urls[10][150],int* cnt_liste){
	int pos_liste = 0,pos_head=0;
	int pos_urls=0;
	int count=0;
	char header[3][10] = {{"https://"},{"http://"},{"www."}};
	printf("Die Header lauten:\n%s\t%s\t\t%s\n",header[0],header[1],header[2]);
	for(;pos_liste<*cnt_liste;pos_liste++){
		
		for(pos_head=0;pos_head<3;pos_head++){
			
			if(strstr(tok_liste[pos_liste],header[pos_head])!= NULL){
				char *tokken = strstr(tok_liste[pos_liste],header[pos_head]);
				while(tokken != tok_liste[pos_liste]){
					tokken = strstr(tok_liste[pos_liste],header[pos_head])-1;
					printf("Der Tokken an der Adresse; %c",*tokken);
					printf("Die Adresse tokke: %p\t Die Adresse Array: %p\n",tokken,
					tok_liste[pos_liste]);
					memmove(tok_liste[pos_liste],tok_liste[pos_liste]+1,strlen
					(tok_liste[pos_liste]));
					printf("Noch ein bisschen: %c\t\t\tDie größe ist: %ld\n",tok_liste[pos_liste][0]
					,strlen(tok_liste[pos_liste]));
				}
				memmove(urls[pos_urls],tok_liste[pos_liste],sizeof(tok_liste[pos_liste]));
				pos_urls++;
				count++;
				break;
			}
		}
		printf("Pos_Liste:%d\tPos_Header:%d\tCount:%d\n",pos_liste,pos_head,count);
	}
	for(int pos_liste=0;pos_liste<count;pos_liste++){
		printf("URL is: %s\n",urls[pos_liste]);}
	return count;
}

