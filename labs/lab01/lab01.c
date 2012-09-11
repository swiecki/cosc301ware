//this repo is online at github.com/swiecki/cosc301ware
#include "lab01.h"
#include <cstdlib.h>
#define NULL 0

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


char *pascal2c(char *string){
	char *toreturn= malloc((strlen(string)+1)*sizeof(char));
	int i = 1;
  for(;i<strlen(string);i++){
		toreturn[i-1] = string[i];
	}
  toreturn[strlen(string)] = '\0';
	return toreturn;
}

char **tokenify(char *string){
	/* iterate through array,
  when you find whitespace, keep going until whitespace ends
before resuming iteration, thus obtaining word count*/
	int i = 0;
	int spaces = 0;
	for(;i<strlen(string);i++){
		if(string[i] == ' ' || string[i] == '\n' || string[i] == '\t'){
			while(string[i] == ' ' || string[i] == '\n' || string[i] == '\t'){
				/*if current index is 0, then we have an opening space and it should not be counted toward wordcount*/
				if(i == 0){
					spaces -=1;
				}
				/*if whitespace is followed by null character
				then we have a trailing whitespace which shouldn't count towards
				wordcount*/
				if(string[i+1] == '\0'){
					spaces -= 1;
					break;
				}
				i++;
			}
		spaces +=1;
		}
	}
	int words = spaces + 1;
	/* allocate enough space for ALL THE WORDS! */
	char **toreturn= malloc((words+1)*sizeof(char*));
	/*Take care of first assignment
		Note- this might be considered very memory intensive,
		but I think it's what the assignment asked for-
		a new string on the heap for every string in the array.
	*/
	int k = 0;
	char *pointer = strtok(string, " \t\n");
	char *newalloc = malloc(sizeof(char)*(strlen(pointer)));
	strcpy(newalloc, pointer);
	toreturn[k] = newalloc;
	k++;
	for(;k<words;k++){
		char *pointer = strtok(NULL, " \t\n");
		char *newalloc = malloc(sizeof(char)*(strlen(pointer)));
		strcpy(newalloc, pointer);
		toreturn[k] = newalloc;
	}
	//could probably use built-in behavior of strtok to do the following:
	toreturn[words] = NULL;
	return toreturn;
}
