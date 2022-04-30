#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){

	//initialize count=0 for 26 letters in freq[]
	for(int i=0;i<26;i++){
		freq[i]=0;
	}
	
	//for loop - go through every letter in array(word[]) until hit null character
	for(int j=0;word[j]!='\0';j++){

		//if letter in index j is a lower case letter, 'a'=97, 'z'=122
		if(word[j]>='a' && word[j]<='z'){
			//freq count +1 in corresponding index
			freq[word[j]-97]++;
		}

		//if letter in index j is a upper case letter, 'A'=65, 'Z'=90
		else if(word[j]>='A' && word[j]<='Z'){
			//freq count +1 in corresponding index
			freq[word[j]-65]++;

		}
	}

   
}
