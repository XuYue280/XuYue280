#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;

	/*write your implementation here*/

	//open input file
	FILE *input_file=fopen(filename,"r");

	int n;
	//read total number of students
	fscanf(input_file,"%d",&n);
	*sizePtr=n;

	class_list=calloc(n,sizeof(*class_list));
	//read each student line by line
	for(int i=0;i<n;i++){
		class_list[i]=calloc(1,sizeof(**class_list));

		fscanf(input_file,"%d",&class_list[i]->student_id);
		fscanf(input_file,"%s",class_list[i]->first_name);
		fscanf(input_file,"%s",class_list[i]->last_name);
		/*printf("Student ID: %d\n", class_list[i]->student_id);
		printf("First Name: %s\n", class_list[i]->first_name);
		printf("Last Name: %s\n", class_list[i]->last_name);
		printf("Grade 1: %d\n", class_list[i]->project1_grade);
		printf("Grade 2: %d\n", class_list[i]->project2_grade);*/
	}


	fclose(input_file);
	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	/*write your implementation here and update the return accordingly*/

	for(int i=0;i<size;i++){
		//arrow operator - check if ID match the target idNo
		if(list[i]->student_id==idNo){
			//return student position
			return i;
		}
	}
	return -1;
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	FILE *input_file=fopen(filename,"r");
	//initialize read_id for first column(non-order id).
	int read_id;

	for(int i=0;i<size;i++){
		//scan first integer in each row and set to read_id
		fscanf(input_file,"%d",&read_id);
		//use "find" function to check if this id exist in the list
		int check=find(read_id,list,size);

		//if student exist
		if(check!=-1){
			//assign second read integer to project1_grade and third read integer to project2_grade
			fscanf(input_file,"%d",&list[check]->project1_grade);
			fscanf(input_file,"%d",&list[check]->project2_grade);
		}
		//if student is not in the list, do nothing
		else
			break;

	}
	fclose(input_file);

}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/

	for(int i=0;i<size;i++){
		//add two grade and divide by 2, they are in type double
		list[i]->final_grade=(list[i]->project1_grade+list[i]->project2_grade)/2.0;
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/

	//open filename in write form
	FILE *output_file=fopen(filename,"w");
	//calculate the final grade(average)
	compute_final_course_grades(list, size);
	//in first line, input total students number
	fprintf(output_file,"%d\n",size);

	for(int i=0;i<size;i++){
		fprintf(output_file,"%d ",list[i]->student_id);
		fprintf(output_file,"%f\n",list[i]->final_grade);

	}
	fclose(output_file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int index=find(idNo,list,*sizePtr);
	if(index!=-1){
		//withdraw corresponding student
		free(list[index]);
		//shift all students after that to left
		for(int i=index;i<*sizePtr-1;i++){
			//after free(), all later student's index will decrease by 1, so +1 to move up
			list[i]=list[i+1];
		}

		//decrease sizePtr value by 1
		(*sizePtr)--;
	}
	else{
		printf("Withdraw info: Student with id %d is not in the list.\n",idNo);
	}

}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i=0;i<*sizePtr;i++){
		free(list[i]);
	}
	free(list);
}
