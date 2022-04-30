#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	
	//initialize i for index counting
	int i=0,count_val=0,count_pos=0;

	//while loop - go through all element in source[]
	while(i<size){
		//if statement-non-zero check
		if(source[i]!=0){
			//extract non-zero elements value and position
			val[count_val]=source[i];
			pos[count_pos]=i;
			//only move to next index when non-zero element occur
			count_pos++;
			count_val++;
		}
		i++;


	}


}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){

	//initialize i for source index counting, j for val[] and pos[] index counting
	int i,j;

	//first for loop - go through the array that need to reconstruct
	for(i=0;i<m;i++){

		//nested for loop - go through val[] and pos[]
		for(j=0;j<n;j++){

			//if statement - to find out the position that match in current source index
			if(pos[j]==i){

				//if position match, then set value[j] into source
				source[i]=val[j];

				//after setting, skip to next source index (i+1)
				break;
			}

			//if doesn't match, keep checking next position index (j+1)
			else{
				continue;
			}
		}
	}
    
	

}
