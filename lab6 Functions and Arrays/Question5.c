#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void string_copy(const char source[], char destination[], int n){
	
	//initialize i for index counting
	int i=0;

	//copy character if and only if it is not a null character, and there is room for destination[] to fill
	//while loop - put i<n-1 instead of i<n because last character is null character
	while(i<n-1){

		//if current character is not null character, copy it into destination[i]
		if(source[i]!='\0'){
			destination[i]=source[i];
		}

		//this is the situation that destination is smaller than source, do not make any change, exit the loop
		else{
			break;
		}
		i++;

	//set last character to null character
	destination[n]='\0';
	}


    
}
