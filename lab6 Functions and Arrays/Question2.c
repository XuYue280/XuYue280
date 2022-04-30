#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=0;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise
	

	//initialize variables
	int i,j,diag_element,sum=0;

	//go through each row with count i
	for(i=0;i<N2;i++){
		sum=0;
		//find diagonal element in each row
		diag_element=fabs(mat[i][i]);

		//go through each column in the same row
		for(j=0;j<N2;j++){

			//add all element in the row
			sum= sum+fabs(mat[i][j]);
		}

		//subtract repeated diag_element to get the sum of other elements
		sum=sum-fabs(mat[i][i]);

		//Assuming diag_element is the biggest for every rows, set isDiag = 1
		if(diag_element>sum){
			isDiag=1;
		}

		//if diag_element less than or equal to sum, it is not diagonally dominant
		else{
			//set isDiag to 0 and exit the loop
			isDiag=0;
			break;
		}


	}





    return isDiag;
}
