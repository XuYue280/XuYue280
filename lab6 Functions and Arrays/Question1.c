#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below

	
	//initialize i for count
	int i;
	//for loop to go through every index in array
	for(i=0;i<size;i++){
		//add two number in array1 and array2 in each index and put into array3 in the same index
		vector3[i]=vector1[i]+vector2[i];

	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
	
    //initialize i for count
    int i;
    //for loop to go through every index in array
    for(i=0;i<size;i++){
    	//add the product of element in same index to prod
    	prod+=vector1[i]*vector2[i];
    }
    

	
	// return the result
    return prod;
}

double norm2(double vector1[], int size){
	//this is the variable holding the L2 norm of the passed vector
    double L2;
	
    
	//write your code here
	// you should call function scalar_prod().

    //use scalar_prod function, input are both vector1 to get the scalar product of itself
    //then take square root
    L2=sqrt(scalar_prod(vector1,vector1,size));
	
	//finally, return the L2 norm 
    return L2;
}

