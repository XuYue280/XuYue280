
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){

rowsNum=3;
colsNum=3;
matrixData=NULL;
matrixData = (int**)malloc(rowsNum*sizeof(int*));

   // Allocate rows for fake "2D array":
   for (int i = 0 ; i < rowsNum ; ++i )
   {
      matrixData[i] = (int*) malloc(colsNum*sizeof(int));
   }

   for (int i = 0 ; i < rowsNum ; ++i )
   	for (int j = 0 ; j < colsNum ; ++j )
   		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
	//if row is negative set row to default =3
	if(row<=0){
		row=3;
	}
	//if col is negative set col to default =3
	if(col<=0){
		col=3;
	}
	rowsNum=row;
	colsNum=col;
	matrixData=NULL;
	//copy from default memory allocation
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	// Allocate rows for fake "2D array":
	for (int i = 0 ; i < row ; i++ ){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
	}

	for (int i = 0 ; i < rowsNum ; i++ )
		for (int j = 0 ; j < colsNum ; j++ )
			matrixData[i][j]=0;
}




Matrix::Matrix(int row, int col, int** table)
{

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/

	//row refers to the size of first element in 2D array, equivalent to sizeof(*table)
	//row=sizeof(table[0]);
	//col refers to the size of whole array
	//col=sizeof(table);

	rowsNum=row;
	colsNum=col;
	//copy from default memory allocation
	matrixData=NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	for (int i = 0 ; i < rowsNum ; ++i ){
		matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}

	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			//read each index in order from "table" and set them to "matrixData"
			matrixData[i][j]=table[i][j];
		}
	}
	

}

int Matrix::getElement(int i, int j){

	//include conditions: negative value and out of the range
	//start from 0, end with i-1/j-1
	if((i<rowsNum&&i>=0)&&(j<colsNum&&j>=0)){
		return matrixData[i][j];
	}
	else{
		throw std::out_of_range( "Invalid indexes." );
	}

	return -1;

}

bool Matrix::setElement(int x, int i, int j){
	//check if index i,j is valid
	if((i<rowsNum&&i>=0)&&(j<colsNum&&j>=0)){
		this->matrixData[i][j]=x;
		return true;

	}
	else{
		return false;
		throw std::out_of_range( "Invalid indexes." );

	}
}

Matrix Matrix::copy(){

	//fix the code and write your implementation below
	//Matrix copy = Matrix (0,0);

    Matrix copy= Matrix(this->rowsNum,this->colsNum);

    for(int i=0;i<rowsNum;i++){
    	for(int j=0;j<colsNum;j++){
    		copy.matrixData[i][j]=matrixData[i][j];
    	}
    }


    return  copy;


}


void Matrix::addTo( Matrix m ){
	
	//check if two matrix have same dimension
	if((m.rowsNum==this->rowsNum)&&(m.colsNum==this->colsNum)){
		//if they have same dimension, add corresponding element
		for(int i=0;i<m.rowsNum;i++){
			for(int j=0;j<m.colsNum;j++){
		    	this->matrixData[i][j]=this->matrixData[i][j]+m.matrixData[i][j];
		    }
		}
	}
	else{
		// not the same dimension
		throw std::invalid_argument( "Invalid operation" );
	}

}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	/* fix the code and write your implementation below */

	//create a new matrix(include row 0, col 0)
	Matrix subM = Matrix (i+1,j+1);

	if((i<this->rowsNum&&i>=0)&&(j<this->colsNum&&j>=0)){
		for(int a=0;a<=i;a++){
			for(int b=0;b<=j;b++){
				//copy matrix from row 0 to a(=i), column from 0 to b(=j)
				subM.matrixData[a][b]=this->matrixData[a][b];
			}
		}
		return subM;
	}
	else{
		throw std::out_of_range( "Submatrix not defined" );
	}
}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return this->rowsNum;
}


int Matrix::getsizeofcols(){

	/* update below return */
	return this->colsNum;
}


bool Matrix::isUpperTr(){

	/* write your implementation here and update return accordingly */
	int a=this->rowsNum;
	//int b=this->colsNum;
	
	for(int i=1;i<a;i++){
		for(int j=0;j<i;j++){
			//break if column index is out of range
			if(j>=colsNum){
				break;
			}
			if(this->matrixData[i][j]!=0){
				return false;
			}
		}
	}
	return true;
}

string Matrix::toString(){

	//set empty string
	string output="";

	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			//add each number in same row and separate by space
			output+=(to_string(matrixData[i][j]) + " ");
		}
		//add new line after adding each row
		output+="\n";
	}

	//return output;
	 return output;
}
