#include "haustier.h"

void name_setzen(haustier *tier, char *name){
	if(!(*name)){							// für den Fall dass das Array leer,
		tier->name[0] = 0;					// wird Tier auf Null gesetzt und die Funktion
		return;								// frühzeitig verlassen.
	}
	char to_flt[100];						// Array für Korrektur
	memset(to_flt,0,100);
	memmove(to_flt,name,strlen(name));		// kopier ins Array.
	only_letter(to_flt);					// alle illegalen Zeichen werden entfernt
	first_letter(to_flt);					// groß und klein Schreibung wird korregiert
	to_flt[6] = 0;							// Name sollen max 6 Zeichen lang sein.
	strncpy(tier->name,to_flt,7);
}
void only_letter(char *name){				
	int find = 0,write = 0;					// find = such idx, write = schreib idx
	for(; name[find] != 0; find++){
		if(ivalid(name[find])){				// wenn ungültig überspring das Zeichen
			continue;
		}else{
			name[write]=name[find];			// sonst schreib ins Array am schreib idx
			write++;	
		}
	}
	name[write] = 0;
}
int ivalid(char symbol){					
	// Prüft nach ASCII für Buchstaben
	if((symbol<65) || (symbol>122)){
		return 1;
	}
	if((symbol>90) && (symbol<97)){
		return 1;
	}
	return 0;
}
void first_letter(char *name){				
	int cnt = 0;					
	for(;*name != 0; name++,cnt++){			// länge des string = cnt
		if(*name<91){						
			*name += 32;					// Innerhlab des Namen sind Buchstaben klein
		}
	}
	*(name-cnt)-= 32;						// 	setzt den Anfangsbuchstaben auf groß
}
void name_ausgeben(char *name, haustier *tier){
	strncpy(name,tier->name,7);				// kopier rüber in das Array, weil Test.
}
