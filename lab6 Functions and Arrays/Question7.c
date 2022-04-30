#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){

	//initialize 'i,j' index counter for val1/pos1, val2/pos2
	int i=0,j=0;
	//initialize 'count' for val3/pos3 general index counting, 'k' for non-zero adding counting
	int count=0,k=0;
	//initialize 'max' to find out the biggest position index in pos1 and pos2, set pos1[0] as first reference
	int max=pos1[0];

	//for loop - (in pos1[]) if next index number is bigger than previous 'max', set it to new 'max'
    for(i=0;i<k1;i++){
    	if(pos1[i]>max){
    		max=pos1[i];
    	}
    }
    //for loop - (in pos2[]) if next index number is bigger than previous 'max', set it to new 'max'
    for(j=0;j<k2;j++){
        if(pos2[j]>max){
         max=pos2[j];
        }
    }
    //reset i and j to 0 for further use
    i=0;
    j=0;


	//while loop - count < max+1 refer to checking input position form index 0 to maximum index
	while(count<max+1){

		//if statement - refers to two values in same position
		if(pos1[i]==count && pos2[j]==count){
			//sum up and set to corresponding position in val3 and pos3
			val3[k]=val1[i]+val2[j];
			//set sparse vector 3 with current position in pos1 (it is equivalent to set pos2[j] since they have same position index)
			pos3[k]=pos1[i];
			//move to next index for both sparse vector 1&2&3(non-zero)
			i++;
			j++;
			k++;
		}
		//else if statement- refers to there is only sparse vector 1 on current 'count'
	    else if(pos1[i]==count){
	    	val3[k]=val1[i];
	        pos3[k]=pos1[i];
	        //move to next index for sparse vector 1&3(non-zero) only
	        i++;
	        k++;
	    }
		//else if statement- refers to there is only sparse vector 2 on current 'count'
	    else if(pos2[j]==count){
	        val3[k]=val2[j];
	        pos3[k]=pos2[j];
	        //move to next index for sparse vector 2&3(non-zero) only
	        j++;
	        k++;
	    }
		//if there is no position match, do nothing
		//move to next index in sparse vector 3(general)
	    count++;
	    }

	
}
