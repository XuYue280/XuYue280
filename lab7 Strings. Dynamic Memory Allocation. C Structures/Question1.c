#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	/*write your implementation here*/

	//question allow us to use "strlen" function to get the srting's length
	int a=strlen(str1);
	int b=strlen(str2);

	//allocate a+b+1*sizeof(char) size of memory (+1 means include null character at the end)
	z=calloc((a+b+1),sizeof(char));

	//if statement - if memory allocation success
	if(z!=NULL){
		int i=0;
		//use i to go through all characters in str1 until hit NULL character
		while(str1[i]!='\0'){
			//* - refer to the value of pointer z
			*(z+i)=str1[i];
			i++;
		}

		//reset i=0 for new order in str2, but keep old value of i (temp) value in z
		int temp=i;
		i=0;
		//same process for str2
		while(str2[i]!='\0'){
			*(z+temp+i)=str2[i];
			i++;
		}
		//set last character to NULL character
		*(z+temp+i)='\0';
	}
	//else statement - if allocation of memory failed, return NULL
	else{
		return z=NULL;
	}

	/* finally, return the string*/
	return z;
	
}
