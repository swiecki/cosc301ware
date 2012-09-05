#include "lab01.h"

void removewhitespace(char *string){
	if(string == 'NULL'){
	 return;
	}
	int i = 0;
	for(;i<strlen(string);i++){
		if(string[i] == '\t' || string[i] == '\n'){
			string[i] = ' ';
		}
	}
	int counter = 0;
	i = 0;
	for(;i<strlen(string);i++){
		if(string[i] != ' '){
			string[counter]=string[i];
			string[i] = ' ';
			counter++;
		}
	}
	i = 0;
	for(;i<strlen(string);i++){
		if(string[i] == ' '){
			string[i] = '\0';
			return;
		}
	}
}

char *c2pascal(char *string){
	if(strlen(string)>127 || string == 'NULL'){
		return 'NULL';
	}
	char *toreturn= malloc((strlen(string)+1)*sizeof(char));
	toreturn[0] = strlen(string);
	int i = 0;
  for(;i<strlen(string);i++){
		toreturn[i+1] = string[i];
	}
	return toreturn;
}


