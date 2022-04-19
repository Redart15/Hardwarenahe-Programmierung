#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void tuh_something();

int main(int argc, char **argv){
	for(int cnt = 0; cnt < argc; cnt++){
		fprintf(stdout,"%2d. Element\tString: %s\n",cnt,argv[cnt]);
	}
	int zahl;
	char option, text[80];
	while((option = getopt(argc,argv,"hg:"))!= -1){
		switch(option){
		case 'h':	
					printf("pos: %d\tstr:%s\n",argc,optarg);
					tuh_something(text);
					break;
		case 'g': 	
					printf("pos: %d\tstr:%s\n",argc,optarg);
					zahl = atoi(optarg);
					printf("Die Zahl ist:%d\n",zahl);
					break;
		case '?':	
					printf("pos: %d\tstr:%s\n",argc,optarg);
					printf("default\n");return 1;
		default: 	break;
		
		}
	}
	argc -= optind;
	argv += optind;
	if(argc){printf("Hier steht ein Text:\n%s\n",argv[0]);}
	else{printf("Dein Eingener Text:\n%s\n",text);}
	return 0;
}

void tuh_something(char* text){
	fgets(text,80,stdin);
}
