/**
	Programmed By : Moaid Hathot
**/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Utilities.h"
#include <map>

using std::cout;
using std::string;
using std::map;


string GetString(FILE* inputSource ){

	int size=0,input;
	char *inputSstring = NULL;

	while( fscanf(inputSource,"%c",&input) == 1 && (char)input!='\n' && input!=EOF){

		if( (inputSstring = (char*)realloc(inputSstring,size+2)) == NULL ){
			fprintf(stderr,"\n\n Faild To (re)Allocate Dynamic Memory ! \n\n");
			WaitForResponse;
			exit(1);
		}

		if( input == '\b' ){
			if( size ){
				inputSstring[size] = '\0';
				inputSstring[size+1] = '\0';
				size--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
		}
		else{
			*(inputSstring+size) = input;
			size++;
		}
	}

	if( !size )
		return NULL;

	*(inputSstring+size) = '\0';

	return inputSstring;
}
/**
	Programmed By : Moaid Hathot
**/