#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"




char **read_words(const char *input_filename, int *nPtr){

	
    char **word_list;

    /*write your implementation here*/
    FILE *input_file=fopen(input_filename,"r");
    int n;
    fscanf(input_file,"%d",&n);
    //assign first line integer as n
    *nPtr=n;


    word_list=calloc(n,sizeof(*word_list));
    //set temp as a temporary storage for word,assume longest word has 50 letters
    char temp[50];

    //read word in each line
    for(int i=0;i<n;i++){
    	//scan each line to get word
    	fscanf(input_file,"%s",temp);
    	//find length in each word
    	int len=strlen(temp);
    	//len+1 refer to including '\0'
    	word_list[i]=calloc(len+1,sizeof(char));
    	strcpy(word_list[i],temp);

    }
    return word_list;
}

int compare_str(const char *str1,const char *str2){

	/*this is a helper function that you can implement and use to facilitate your development*/
   	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/

	/*write your implementation here and update the return accordingly*/
    
	//get length from each two words for comparing
	int val_1=strlen(str1);
	int val_2=strlen(str2);

	int check_min;
	//find the shortest length
	if(val_1<val_2)
		check_min=val_1;
	else
		check_min=val_2;

	//loop only focus on common number of letters
	for(int i=0;i<check_min;i++){
		//if letter in str1 is bigger than str2 in ASCll, return 1 (swap)
		if(str1[i]>str2[i])
			return 1;
		//if letters in same index are same keep looping
		else if(str1[i]==str2[i])
			continue;
		//if if letter in str1 is smaller than str2 in ASCll, return 0
		else
			return 0;
	}


	return -1;

}

void sort_words(char **words, int size){
   
	/*write your implementation here*/

	//insertion sort method
	int i,j;
	char* check;
	for(i=1;i<size;i++) {
		//set check to keep unchanged
		check=words[i];
		//use another index to go through back to front
	    j=i-1;
	    while (j>=0) {
	    	//use compare function to compare to strings
	    	if(compare_str(words[j],check)==1) {
	    		//if compare_str = 1, swap two term
	    		swap(&words[j],&words[j+1]);
	    		//move to front index
	    		j--;
	        }
	    	//if current word is bigger than check, skip to next word
	    	else{
	    		//move to front index
	    		j--;
	    	}
	    }
	}
}





void swap(char **str1, char **str2){
 
	/*this is a helper function that you can implement and use to facilitate your development*/

	//order doesn't matter
	char* temp;
	temp=*str1;
	*str1=*str2;
	*str2=temp;
}

void sort2_words(char **words, int size){

   
	/*write your implementation here*/
	//personal favorite method
	int i,j;
	//first loop set check word form index 0 to size-1
	for(i=0;i<size-1;i++){
		//second loop use first loop index word, then compare all words after
		//keep checking all words until hit the end
		for(j=i+1;j<size;j++){
			if(compare_str(words[i],words[j])==1){
				//if later words is smaller, swap
				swap(&words[i],&words[j]);
			}
		}
	}
    
}

