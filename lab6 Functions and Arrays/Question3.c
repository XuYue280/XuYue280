#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	//initialize i for row, j for column, k for assign value, count for counting
	int i,j,k,count=0;

	//for loop - go through every diagonals in top half part (including center diagonal)
	for(k=0;k<N3;k++){

		//set j=0 for each diagonal, i=k means start a new row each time
		i=k;
		j=0;

		//while loop - go through each elements in diagonal
		while(i>=0){
			arr[count]=mat[i][j];
			//move to next top-right element
			i--;
			j++;
			count++;
		}
	}

	//for loop - go through every diagonals in bottom half part
	for(k=1;k<N3;k++){
		//start second column each time
		j=k;
		//start from last row each time
		i=N3-1;

		while(j<N3){
			arr[count]=mat[i][j];
			//move to next top-right element
			i--;
			j++;

			count++;
		}
	}

}
