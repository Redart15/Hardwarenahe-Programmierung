#include <stdio.h> 
#include <string.h> 


int urls_finden(char urls[10][150], char *text);

int main(){
	char urls[10][150];
	//~ char *text = "https:/ach kein Bock mehr";
	char* text = 	"Das beste Video: https://www.youtube.com/watch?v=dQw4w9WgXcQ "
					"Ein Link zum ILIAS: https://ilias.hhu.de/ilias.php?ref_id=1&cmdClass=ilrepositorygui&cmdNode=va&baseClass=ilrepositorygui ,"
					"Wikipedia-Eintrag zur Programmiersprache C https://en.wikipedia.org/wiki/C_(programming_language) "
					"Microsoft https://www.youtube.com/oembed?url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DVhh_GeBPOhs&format=json "
					"Klackernde Tastaturen https://i.imgur.com/pbqiLgY.gif "
					"Schlecht kommentierter Code https://raw.githubusercontent.com/ProjectDock/programming-memes/main/src/MEMES/images/I-am-Harshdeep/meme.png "
					"Schlecht kommentierter Code 2 https://abstrusegoose.com/strips/you_down_wit_OPC-yeah_you_know_me.png "
					"https://i.imgur.com/5DlqfCl.jpg Sonderfaelle "
					"C vs C++ https://devhumor.com/content/uploads/images/December2016/c++-c-class.jpg "
					"Hyperlink https://i.imgur.com/cV9m29E.png "
					"Denkt daran eure Strings zu terminieren und eure Variablen zu initialisieren!";
	int anzahl = urls_finden(urls,text);
	//~ int pos_url=0;
	//~ for(;anzahl>pos_url;pos_url++){
		//~ for(int cnt = 0;urls[pos_url][cnt]!= '\0';cnt++){
			//~ if(cnt>999){printf("Pos%d ist nicht terminiert\n",pos_url);return 1;}
		//~ }
		//~ printf("Pos%d ist terminiert\n",pos_url);
	//~ }
	//~ printf("Die Liste ist terminiert\n");
	printf("\nAnzahl ist: %d \n",anzahl);
}
